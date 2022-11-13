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


class ControllerNode(Node):

    class TelloState(Enum):
        LANDED = 1
        TAKINGOFF = 2
        HOVERING = 3
        FLYING = 4
        LANDING = 5
        NONE = 0

    state = TelloState.LANDED
    next_state = TelloState.NONE
    action_done = False

    def __init__(self):
        super().__init__('controller_node')
        self.tello_controller = self.create_subscription(Empty, '/iisrl/tello_controller', self.main_callback, 10)
        self.tello_response = self.create_subscription(TelloResponse, '/drone1/tello_response', self.tello_response_callback, 10)
        self.aruco_sub = self.create_subscription(ArucoMarkers, '/aruco_markers', self.get_markers, 10)

        self.tello_service_server = self.create_service(TelloState, '/iisrl/tello_state', self.state_callback)
        self.tello_service_client = self.create_client(TelloAction, '/drone1/tello_action')
        self.service_request = TelloAction.Request()

        self.pose = Pose()

    def state_callback(self, request, response):
        response.state = str(self.state)
        response.value = int(self.state.value)

        return response

    def main_callback(self, msg):
        self.get_logger().info("Uruchomiono wezeł")
        self.action_done = False # False, gdy istnieje misja do wykonania; True, gdy testujemy start i ladowanie

        if self.state is not self.TelloState.HOVERING:  
            self.state = self.TelloState.TAKINGOFF
            if self.state == self.TelloState.TAKINGOFF:
                self.taking_off_func()

    def tello_response_callback(self, msg):
        if msg.rc == 1:
            self.state = self.next_state
            self.next_state = self.TelloState.NONE

    def taking_off_func(self):
        # start drona
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        self.service_request.cmd = 'takeoff'
        self.tello_service_client.call_async(self.service_request)
        time.sleep(3)
        self.state = self.TelloState.HOVERING   

    def mission_func(self):
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        print("DUPA")
        print(self.pose.position.z)
        if self.pose.position.z > 0.4:
            x_vel = 0.1
        elif self.pose.position.z < - 0.4:
            x_vel = -0.1
        else:
            x_vel = 0.0

        if self.pose.position.y > 0.3:
            y_vel = 0.0
        elif self.pose.position.y < - 0.3:
            y_vel = -0.0
        else:
            y_vel = 0.0

        if self.pose.position.x > 0.3:
            z_vel = 0.0
        elif self.pose.position.x < - 0.3:
            z_vel = -0.0
        else:
            z_vel = 0.0


        print(f'rc {x_vel} {y_vel} {z_vel} 0')
        self.service_request.cmd = f'rc {x_vel} {y_vel} {z_vel} 0'
        self.tello_service_client.call_async(self.service_request)
        # time.sleep(0.1)

        if self.pose.position.z < 0.3:
            self.action_done = True

        self.action_done = False
        if self.action_done:
            self.service_request.cmd = 'rc 0 0 0 0'
            self.tello_service_client.call_async(self.service_request)
            print("SKONCZONE")
            # landing_func()


    def landing_func(self):
        self.state = self.TelloState.LANDING

        # ladowanie drona
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        self.service_request.cmd = 'land'
        self.tello_service_client.call_async(self.service_request)

    def get_markers(self, msg):
        self.marker_list = msg.marker_ids
        self.poses_list = msg.poses 
        # print("DEJ MARKER")
        if 0 in self.marker_list:
            id = self.marker_list.index(0)
            self.pose = self.poses_list[id]
            # print(self.pose.position)
        
        if self.state == self.TelloState.HOVERING and not self.action_done:
            self.mission_func()
        
            
            


def main(args=None):
    rclpy.init()

    cn = ControllerNode()
    
    rclpy.spin(cn)
    cn.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
