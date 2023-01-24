from tello_msgs.srv import TelloAction
from tello_msgs.msg import TelloResponse
from tello_interface.srv import TelloState
from ros2_aruco_interfaces.msg import ArucoMarkers
from geometry_msgs.msg import PoseArray, Pose
from nav_msgs.msg import Odometry
from std_msgs.msg import Empty
from threading import Thread, Event

import rclpy
from rclpy.node import Node

import time
from enum import Enum
from math import sqrt
import numpy as np

from .pid import PID


# PID USAGE
# https://github.com/shijq23/alpha_drone/blob/main/face_track/src/face_track/tracker.py
class TelloTimer(Thread):
    interval = 1.0
    running = None
    func = None

    def __init__(self, interval, event, func):
        Thread.__init__(self)
        self.running = event
        self.interval = interval
        self.func = func


    def run(self):
        while not self.running.wait(self.interval):
            self.func()


class ControllerNode(Node):

    def __init__(self):
        super().__init__('controller_node')

        self.stop_flag = Event()
        self.tello_timer = TelloTimer(0.1, self.stop_flag, self.tello_signal)
        self.tello_timer.start()

        self.fb_v = 0.0
        self.lr_v = 0.0
        self.ud_v = 0.0

        self.declare_parameter('follow_markers', '1,2,3')
        self.declare_parameter('drone_topic', '/tello_action')
        self.declare_parameter('aruco_topic', '/aruco_markers')
        self.declare_parameter('position_topic', '/repeater/tello_1/pose/info')
        self.declare_parameter('second_mission', 0)
        self.declare_parameter('dev_in_simulation', 1)

        self.follow_markers = self.get_parameter('follow_markers').get_parameter_value().string_value
        self.second_mission = self.get_parameter('second_mission').get_parameter_value().integer_value
        self.dev_in_simulation = self.get_parameter('dev_in_simulation').get_parameter_value().integer_value
        self.drone_topic = self.get_parameter('drone_topic').get_parameter_value().string_value
        self.aruco_topic = self.get_parameter('aruco_topic').get_parameter_value().string_value
        self.position_topic = self.get_parameter('position_topic').get_parameter_value().string_value

        self.aruco_sub = self.create_subscription(ArucoMarkers, self.aruco_topic, self.get_real_markers, 10)

        if self.dev_in_simulation == 1:
            self.position_sub = self.create_subscription(Odometry, self.position_topic, self.position_callback, 10)
        else:
            self.position_sub = self.create_subscription(Pose, self.position_topic, self.position_callback, 10)


        self.tello_service_client = self.create_client(TelloAction, self.drone_topic)
        self.service_request = TelloAction.Request()

        self.pos_x = 0.0
        self.pos_y = 0.0
        self.pos_z = 0.0

        self.first_mission_done = False 
        self.second_mission_done = False 
        self.state = 0

        self.follow_list = []
        self.coord_list = []
        self.fly_around_index = 0

        self.real_marker_list = []
        self.real_poses_list = []
        self.real_coord_list = []
        self.got_coordinates = False
        self.fly_aruco_index = 0

        self.fb_pid = PID('fb', kP=1.68, kI=0.86, kD=1.68)
        self.ud_pid = PID('ud', kP=16.0, kI=2.02, kD=10.8)
        self.lr_pid = PID('lr', kP=3.0, kI=0.1, kD=2.0)
        self.fb_pid.reset()
        self.lr_pid.reset()
        self.ud_pid.reset()

        self.get_logger().info(f'follow_markers: {self.follow_markers}, drone_topic: {self.drone_topic}, aruco_topic: {self.aruco_topic}, position_topic: {self.position_topic}, second_mission: {self.second_mission}, dev_in_simulation: {self.dev_in_simulation}')


    def tello_signal(self):
        self.service_request.cmd = f'rc {self.fb_v} {self.lr_v} {self.ud_v} 0'
        # self.service_request.cmd = f'rc {int(self.lr_v)} {int(self.fb_v)} 0 0'
        # self.service_request.cmd = f'rc 0 0 0 0'
        # self.service_request.cmd = f'rc 0 {int(self.fb_v)} 0 0'
        self.get_logger().info(f'GETTING POSITION: ({self.pos_x}, {self.pos_y}, {self.pos_z})')
        self.get_logger().info(self.service_request.cmd)
        self.tello_service_client.call_async(self.service_request)


    def parse_params(self):
        marker_no = rospy.get_param('~aruco_no', 0)
        topic = rospy.get_param('~topic', '/tello_action')
        return {
            'marker_n': marker_no,
            'topic': topic,
        }


    def position_callback(self, msg):
        if self.dev_in_simulation == 1:
            self.pos_x = msg.pose.pose.position.x
            self.pos_y = msg.pose.pose.position.y
            self.pos_z = msg.pose.pose.position.z
        else:
            self.pos_x = msg.position.x
            self.pos_y = msg.position.y
            self.pos_z = msg.position.z

        # self.get_logger().info(f'GETTING POSITION: ({self.pos_x}, {self.pos_y}, {self.pos_z})')

        self.state_machine()


    def state_machine(self):
        if self.state == 0:
            self.get_logger().info("TAKING OFF")

            self.get_marker_numbers()
            self.add_markers_to_fly_around()

            self.take_off()

        elif self.state == 1:
            print("FLYING AROUND")
            self.fly_around()

        elif self.state == 2:
            if self.second_mission == 1:
                print("FLYING TO ARUCO")
                self.fly_aruco()
            else:
                self.state = 3

        elif self.state == 3:
            print("LANDING")
            self.land()
    
    def get_marker_numbers(self):
        self.follow_list.clear()

        for i in self.follow_markers.split(","):
            self.follow_list.append(int(i))
        
        self.get_logger().info(f"MARKERS TO FOLLOW LIST: {self.follow_list}")


    def add_markers_to_fly_around(self):
        markers = {
        0: (0, 0, 1),
        1: (1, 1, 1),
        2: (0, 0, 1),
        3: (1, -1, 1),
        4: (0, 0, 1),
        5: (-1, -1, 1),
        6: (0, 0, 1),
        7: (-1, 1, 1),
        8: (0, 0, 1),
        15: (-2, 0, 1),
        21: (0, 0, 1)
        }

        self.coord_list.clear()

        for k in markers.keys():
            if k in self.follow_list:
                self.coord_list.append(markers[k])

        self.get_logger().info(f"COORDINATES LIST: {self.coord_list}")


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
        time.sleep(3)
        # self.state = 0

    def max_value(self, velocity):
        if abs(velocity) > 30:
            if velocity > 0 :
                velocity = 30
            else:
                velocity = -30
        
        return velocity


    def fly_around(self):
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        drone = (self.pos_x, self.pos_y, self.pos_z)
        marker = self.coord_list[self.fly_around_index]

        dst = np.linalg.norm(np.array(drone)-np.array(marker))
        # self.get_logger().info(f'DISTANCE TO TARGET, {dst}')

        # forward_backward_velocity
        self.fb_v = float(self.fb_pid.update(process_variable=self.pos_x, set_point=marker[0]))
        self.fb_v = self.max_value(self.fb_v)

        # left_right_velocity
        self.lr_v = float(self.lr_pid.update(process_variable=self.pos_y, set_point=marker[1]))
        self.lr_v = self.max_value(self.lr_v)

        # up_down_velocity
        self.ud_v = float(self.ud_pid.update(process_variable=self.pos_z, set_point=marker[2]))
        self.ud_v = self.max_value(self.ud_v)


        # self.get_logger().info(f'rc {fb_v} {lr_v} {ud_v}')
        # self.service_request.cmd = f'rc {fb_v} {lr_v} {ud_v} 0'
        # self.tello_service_client.call_async(self.service_request)

        if dst < 0.3:
            self.get_logger().info(f'TARGET {self.fly_around_index} REACHED')
            self.fly_around_index += 1
            if self.fly_around_index >= len(self.follow_list):
                self.first_mission_done = True
                self.get_logger().info('LAST TARGET REACHED')

        if self.first_mission_done:
            self.state = 2
            self.service_request.cmd = 'rc 0 0 0 0'
            self.tello_service_client.call_async(self.service_request)
            self.get_logger().info('FLYING AROUND FINISHED')


    def fly_aruco(self):
        if not self.got_coordinates:
            self.choose_marker()
            self.got_coordinates = True

        drone = (self.pos_x, self.pos_y, self.pos_z)
        marker = self.real_coord_list[self.fly_aruco_index]

        dst = np.linalg.norm(np.array(drone)-np.array(marker))
        # self.get_logger().info(f'DISTANCE TO MARKER: {dst}')

        # forward_backward_velocity
        self.fb_v = float(self.fb_pid.update(process_variable=self.pos_x, set_point=marker[0]))
        self.fb_v = self.max_value(self.fb_v)

        # left_right_velocity
        self.lr_v = float(self.lr_pid.update(process_variable=self.pos_y, set_point=marker[1]))
        self.lr_v = self.max_value(self.lr_v)

        # up_down_velocity
        self.ud_v = float(self.ud_pid.update(process_variable=self.pos_z, set_point=marker[2]))
        self.ud_v = self.max_value(self.ud_v)


        # self.service_request.cmd = f'rc {fb_v} {lr_v} {ud_v} 0'
        # self.get_logger().info(self.service_request.cmd)
        # self.tello_service_client.call_async(self.service_request)

        if dst < 0.15:
            self.get_logger().info(f'MARKER {self.fly_aruco_index} REACHED')
            self.fly_aruco_index += 1
            if self.fly_aruco_index >= len(self.real_coord_list):
                self.second_mission_done = True
                self.get_logger().info('LAST MARKER REACHED')

        if self.second_mission_done:
            self.state = 3
            self.service_request.cmd = 'rc 0 0 0 0'
            self.tello_service_client.call_async(self.service_request)
            self.get_logger().info('FLYING TO ARUCO FINISHED')
        
        # self.get_logger().info(f"real_coord_list: {self.real_coord_list}")


    def get_real_markers(self, msg):
        self.real_marker_list = msg.marker_ids
        self.real_poses_list = msg.poses 

    def choose_marker(self):
        for marker_no in self.follow_list:
            if marker_no in self.real_marker_list:
                list_id = self.real_marker_list.index(marker_no)

                marker_pose = self.real_poses_list[list_id]

                if self.dev_in_simulation == 1:
                    x = self.pos_x + (marker_pose.position.z*2.5) - 1
                    y = self.pos_y + (-marker_pose.position.x*3)
                    z = self.pos_z + (-marker_pose.position.y*3)
                else:
                    x = self.pos_x + (marker_pose.position.z) - 1
                    y = self.pos_y + (-marker_pose.position.x)
                    z = self.pos_z + (-marker_pose.position.y)

                self.real_coord_list.append((x, y, z))

        self.real_coord_list.append((0, 0, 1))
        

        
def main(args=None):
    rclpy.init()

    cn = ControllerNode()
    
    rclpy.spin(cn)
    cn.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
