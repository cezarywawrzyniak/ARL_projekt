from tello_msgs.srv import TelloAction
from tello_msgs.msg import TelloResponse
from tello_interface.srv import TelloState
from ros2_aruco_interfaces.msg import ArucoMarkers
from geometry_msgs.msg import PoseArray, Pose
from nav_msgs.msg import Odometry
from std_msgs.msg import Empty

import rclpy
from rclpy.node import Node

import time
from enum import Enum
from math import sqrt
import numpy as np

from .pid import PID


# PID USAGE
# https://github.com/shijq23/alpha_drone/blob/main/face_track/src/face_track/tracker.py

class ControllerNode(Node):

    state = 0
    action_done = False
    pose = Pose()

    def __init__(self):
        super().__init__('controller_node')

        self.declare_parameter('follow_markers', '1,2,3')
        self.declare_parameter('drone_topic', '/tello_action')
        self.declare_parameter('aruco_topic', '/aruco_markers')
        self.declare_parameter('position_topic', '/repeater/tello_1/pose/info')


        self.follow_markers = self.get_parameter('follow_markers').get_parameter_value().string_value
        self.drone_topic = self.get_parameter('drone_topic').get_parameter_value().string_value
        self.aruco_topic = self.get_parameter('aruco_topic').get_parameter_value().string_value
        self.position_topic = self.get_parameter('position_topic').get_parameter_value().string_value

        self.get_logger().info(f'{self.follow_markers}, {self.drone_topic}, {self.aruco_topic}, {self.position_topic}')

        self.tello_controller = self.create_subscription(Empty, '/tello_controller', self.main_callback, 10)
        self.aruco_sub = self.create_subscription(ArucoMarkers, self.aruco_topic, self.get_markers, 10)
        self.position_sub = self.create_subscription(Odometry, self.position_topic, self.position_callback, 10)
        self.tello_service_client = self.create_client(TelloAction, self.drone_topic)
        self.service_request = TelloAction.Request()

        self.pos_x = 0.0
        self.pos_y = 0.0
        self.pos_z = 0.0

        self.follow_list = []
        self.coord_list = []
        self.index = 0

        self.fb_pid = PID('fb', kP=1.68, kI=0.86, kD=1.68)
        # terms for up and down speed control
        self.ud_pid = PID('ud', kP=16.0, kI=2.02, kD=10.8)
        # terms for left and right speed control
        self.lr_pid = PID('lr', kP=3.0, kI=0.1, kD=2.0)
        # terms for yaw speed control
        # self.yaw_pid = PID('yaw', kP=-0.5, kI=-0.01, kD=-0.1, SP=0.0)
        self.pid_cv: tuple = (0, 0, 0, 0)

        self.fb_pid.reset()
        self.lr_pid.reset()
        self.ud_pid.reset()
        # self.yaw_pid.reset()

    def parse_params(self):
        marker_no = rospy.get_param('~aruco_no', 0)
        topic = rospy.get_param('~topic', '/tello_action')
        return {
            'marker_n': marker_no,
            'topic': topic,
        }

    def position_callback(self, msg):
        self.pos_x = msg.pose.pose.position.x
        self.pos_y = msg.pose.pose.position.y
        self.pos_z = msg.pose.pose.position.z
        self.state_machine()

    def state_machine(self):
        if self.state == 0:
            print("TAKING OFF")
            self.get_logger().info("Uruchomiono wezeł")

            self.follow_list.clear()
            for i in self.follow_markers.split(","):
                self.follow_list.append(int(i))
            self.get_logger().info(f"MARKERS TO FOLLOW LIST {self.follow_list}")

            self.take_off()
            
        elif self.state == 10:
            print("SPINNING")
            self.spin()

        elif self.state == 1:
            print("FLYING")
            self.fly_stupid()

        elif self.state == 2:
            print("LANDING")
            self.land()

    def main_callback(self, msg):
        self.action_done = False 
        self.state_machine()
        

    def get_markers(self, msg):
        markers = {
        0: (1, 1, 1),
        1: (2, 2, 1),
        2: (1, 1, 1),
        3: (-2, -2, 1),
        4: (1, 1, 1),
        5: (3, -4, 1),
        6: (1, 1, 1),
        7: (-5, 6, 1),
        8: (1, 1, 1),
        9: (-3, 0, 1),
        21: (0, 0, 1)
        }

        self.coord_list.clear()

        for k in markers.keys():
            if k in self.follow_list:
                self.coord_list.append(markers[k])

        self.get_logger().info(f"COORD LIST{self.coord_list}")

        # self.marker_list = msg.marker_ids
        # self.poses_list = msg.poses 
        # if self.follow_marker in self.marker_list:
        #     id = self.marker_list.index(self.follow_marker)
        #     self.pose = self.poses_list[id]


    def take_off(self):
        # start drona
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        self.service_request.cmd = 'takeoff'
        self.tello_service_client.call_async(self.service_request)
        self.state = 1
        time.sleep(3)

    def land(self):
        # ladowanie drona
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        self.service_request.cmd = 'land'
        self.tello_service_client.call_async(self.service_request)   
        # self.state = 0
        time.sleep(3)

    def fly_stupid(self):
        self.state = 1
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        drone = (self.pos_x, self.pos_y, self.pos_z)
        marker = self.coord_list[self.index]

        dst = np.linalg.norm(np.array(drone)-np.array(marker))
        self.get_logger().info(f'DISTANCE TO TARGET, {dst}')

        # forward_backward_velocity
        fb_v = float(self.fb_pid.update(process_variable=self.pos_x, set_point=marker[0]))

        # left_right_velocity
        lr_v = float(self.lr_pid.update(process_variable=self.pos_y, set_point=marker[1]))

        # up_down_velocity
        ud_v = float(self.ud_pid.update(process_variable=self.pos_z, set_point=marker[2]))


        self.get_logger().info(f'rc {fb_v} {lr_v} {ud_v}')
        self.service_request.cmd = f'rc {fb_v} {lr_v} {ud_v} 0'
        self.tello_service_client.call_async(self.service_request)

        if dst < 0.3:
             self.get_logger().info(f'TARGET {self.index} REACHED')
             self.index += 1
             if self.index >= len(self.follow_list):
                self.action_done = True
                self.get_logger().info('LAST TARGET REACHED')

        if self.action_done:
            self.state = 2
            self.service_request.cmd = 'rc 0 0 0 0'
            self.tello_service_client.call_async(self.service_request)
            print("SKONCZONE")

    # def fly_mission(self):
    #     self.state = 1
    #     while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
    #         self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

    #     distance = sqrt(self.pose.position.x * self.pose.position.x + self.pose.position.y * self.pose.position.y + self.pose.position.z * self.pose.position.z)
    #     # print("DISTANCE:", distance, self.follow_marker)
    #     print("Z:", self.pose.position.z, self.follow_marker)

    #     if distance > 0.3:
    #         # left_right_velocity
    #         lr_v = -float(self.lr_pid.update(self.pose.position.x))

    #         # forward_backward_velocity
    #         fb_v = float(self.fb_pid.update(self.pose.position.z - 0.15))

    #         # up_down_velocity
    #         ud_v = -float(self.ud_pid.update(self.pose.position.y))

    #     else:
    #         lr_v = 0
    #         fb_v = 0
    #         ud_v = 0
    #         yaw_v = 0

    #     print(f'rc {fb_v/2} {lr_v} {ud_v} 0')
    #     self.service_request.cmd = f'rc {fb_v} {lr_v} {ud_v} 0'
    #     self.tello_service_client.call_async(self.service_request)

    #     if self.pose.position.z < 0.15:
    #         self.action_done = True

    #     if self.action_done:
    #         self.state = 2
    #         self.service_request.cmd = 'rc 0 0 0 0'
    #         self.tello_service_client.call_async(self.service_request)
    #         print("SKONCZONE")


        
def main(args=None):
    rclpy.init()

    cn = ControllerNode()
    
    rclpy.spin(cn)
    cn.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
