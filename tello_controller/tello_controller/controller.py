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


class ControllerNode(Node):

    state = 0
    action_done = False
    pose = Pose()
    follow_marker = 6

    def __init__(self):
        super().__init__('controller_node')
        self.tello_controller = self.create_subscription(Empty, '/iisrl/tello_controller', self.main_callback, 10)
        self.aruco_sub = self.create_subscription(ArucoMarkers, '/aruco_markers', self.get_markers, 10)

        self.tello_service_client = self.create_client(TelloAction, '/drone1/tello_action')
        self.service_request = TelloAction.Request()



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
        print(distance)

        if self.pose.position.z > 0.15:
            x_vel = 0.1
        elif self.pose.position.z < - 0.15:
            x_vel = -0.1
        else:
            x_vel = 0.0

        if self.pose.position.y > 0.05:
            z_vel = -0.05
        elif self.pose.position.y < - 0.05:
            z_vel = 0.05
        else:
            z_vel = 0.0

        if self.pose.position.x > 0.05:
            y_vel = -0.05
        elif self.pose.position.x < - 0.05:
            y_vel = 0.05
        else:
            y_vel = 0.0


        print(f'rc {x_vel} {y_vel} {z_vel} 0')
        self.service_request.cmd = f'rc {x_vel} {y_vel} {z_vel} 0'
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
