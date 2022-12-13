from tello_msgs.srv import TelloAction
from tello_msgs.msg import TelloResponse
from tello_interface.srv import TelloState
from ros2_aruco_interfaces.msg import ArucoMarkers
from geometry_msgs.msg import PoseArray, Pose

import time
from enum import Enum

import rclpy
from rclpy.node import Node

from std_msgs.msg import Empty

from math import sqrt
from .pid import PID


# PID USAGE
# https://github.com/shijq23/alpha_drone/blob/main/face_track/src/face_track/tracker.py

class ControllerNode(Node):

    state = 0
    action_done = False
    pose = Pose()
    follow_marker = 0

    def __init__(self):
        super().__init__('controller_node')
        self.tello_controller = self.create_subscription(Empty, '/iisrl/tello_controller', self.main_callback, 10)
        self.aruco_sub = self.create_subscription(ArucoMarkers, '/aruco_markers', self.get_markers, 10)

        self.tello_service_client = self.create_client(TelloAction, '/drone1/tello_action')
        self.service_request = TelloAction.Request()

        self.fb_pid = PID('fb',
                          kP=0.5,
                          kI=0.01,
                          kD=0.1,
                          SP=0.0)
        # terms for up and down speed control
        self.ud_pid = PID('ud', kP=0.5, kI=0.01, kD=0.1, SP=0.0)
        # terms for left and right speed control
        self.lr_pid = PID('lr', kP=-0.5, kI=-0.01, kD=-0.1, SP=0.0)
        # terms for yaw speed control
        self.yaw_pid = PID('yaw', kP=-0.5, kI=-0.01, kD=-0.1, SP=0.0)
        self.pid_cv: tuple = (0, 0, 0, 0)

        self.fb_pid.reset()
        self.lr_pid.reset()
        self.ud_pid.reset()
        self.yaw_pid.reset()



    def main_callback(self, msg):
        self.action_done = False 

        if self.state == 0:
            print("TAKING OFF")
            self.get_logger().info("Uruchomiono wezeł")
            self.take_off()

        elif self.state == 1:
            print("FLYING")
            self.fly_mission()

        elif self.state == 2:
            print("LANDING")
            self.land()

    def get_markers(self, msg):
        self.marker_list = msg.marker_ids
        self.poses_list = msg.poses 
        # print("DEJ MARKER")
        if self.follow_marker in self.marker_list:
            id = self.marker_list.index(self.follow_marker)
            self.pose = self.poses_list[id]
            # print(self.pose.position)
        
        if self.state == 1 and not self.action_done:
            self.fly_mission()

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
        self.state = 0
        time.sleep(3)

    def fly_mission(self):
        self.state = 1
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        distance = sqrt(self.pose.position.x * self.pose.position.x + self.pose.position.y * self.pose.position.y + self.pose.position.z * self.pose.position.z)
        print("DISTANCE:", distance, self.follow_marker)

        def clip(x: int, lower: int = -100, upper: int = 100) -> int:
            return max(lower, min(upper, x))

        if distance > 0.1:
            # left_right_velocity
            # lr_v = int(self.lr_pid.update(cx))
            # lr_v = clip(lr_v, -5, 5)
            lr_v = 0

            # forward_backward_velocity
            fb_v = float(self.fb_pid.update(self.pose.position.z))
            # fb_v = clip(fb_v, -30, 30)
            # fb_v = 0

            # up_down_velocity
            ud_v = float(self.ud_pid.update(self.pose.position.y))
            # ud_v = clip(ud_v, -20, 20)
            # ud_v = 0

            # yaw_velocity
            yaw_v = float(self.yaw_pid.update(self.pose.position.x))
            # yaw_v = clip(yaw_v, -30, 30)
            # yaw_v = 0
        else:
            lr_v = 0
            fb_v = 0
            ud_v = 0
            yaw_v = 0

        # if self.pose.position.z > 0.15:
        #     x_vel = 0.1
        # elif self.pose.position.z < - 0.15:
        #     x_vel = -0.1
        # else:
        #     x_vel = 0.0

        # if self.pose.position.y > 0.05:
        #     z_vel = -0.05
        # elif self.pose.position.y < - 0.05:
        #     z_vel = 0.05
        # else:
        #     z_vel = 0.0

        # if self.pose.position.x > 0.05:
        #     y_vel = -0.05
        # elif self.pose.position.x < - 0.05:
        #     y_vel = 0.05
        # else:
        #     y_vel = 0.0

        # print(f'rc {x_vel} {y_vel} {z_vel} 0')
        # self.service_request.cmd = f'rc {x_vel} {y_vel} {z_vel} 0'

        print(f'rc {fb_v/5} {0} {0} 0')
        self.service_request.cmd = f'rc {fb_v/5} {0} {0} 0'
        self.tello_service_client.call_async(self.service_request)
        # time.sleep(0.1)

        if self.pose.position.z < 0.3:
            self.action_done = True

        if self.action_done:
            self.state = 2
            self.service_request.cmd = 'rc 0 0 0 0'
            self.tello_service_client.call_async(self.service_request)
            print("SKONCZONE")


        
def main(args=None):
    rclpy.init()

    cn = ControllerNode()
    
    rclpy.spin(cn)
    cn.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
