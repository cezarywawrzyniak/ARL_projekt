from tello_msgs.srv import TelloAction
from tello_msgs.msg import TelloResponse
from tello_interface.srv import TelloState

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

        self.tello_service_server = self.create_service(TelloState, '/iisrl/tello_state', self.state_callback)
        self.tello_service_client = self.create_client(TelloAction, '/drone1/tello_action')
        self.service_request = TelloAction.Request()

    def state_callback(self, request, response):
        response.state = str(self.state)
        response.value = int(self.state.value)

        return response

    def main_callback(self, msg):
        self.get_logger().info("Uruchomiono wezeł")
        self.action_done = True # False, gdy istnieje misja do wykonania; True, gdy testujemy start i ladowanie

        self.state = self.TelloState.LANDED
        self.next_state = self.TelloState.TAKINGOFF

        self.controller()

    def controller(self):
        if self.state == self.TelloState.LANDED and self.next_state == self.TelloState.TAKINGOFF:
            self.taking_off_func()

        if self.state == self.TelloState.HOVERING:
            if self.action_done:
                self.action_done = False
                self.landing_func()
            else:
                self.flying_func()

    def tello_response_callback(self, msg):
        if msg.rc == 1:
            self.state = self.next_state
            self.next_state = self.TelloState.NONE

        self.controller()

    def taking_off_func(self):
        self.state = self.TelloState.TAKINGOFF
        self.next_state = self.TelloState.HOVERING

        # start drona
        while not self.tello_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Oczekuje na dostepnosc uslugi Tello...")

        self.service_request.cmd = 'takeoff'
        self.tello_service_client.call_async(self.service_request)

    def flying_func(self):
        self.state = self.TelloState.FLYING
        self.next_state = self.TelloState.FLYING

        if self.action_done:
            self.next_state = self.TelloState.HOVERING
        else:
            # aktywuj misje do wykonania (np. mission_func())
            pass
            ###          

    def mission_func(self):
        # misja do wykonania
        ###

        self.controller()

    def landing_func(self):
        self.state = self.TelloState.LANDING
        self.next_state = self.TelloState.LA/work/tello_ros_ws/src/tello_controller/tello_controllerNDED

        # opis procedury ladowania
        ###


def main(args=None):
    rclpy.init()

    cn = ControllerNode()

    rclpy.spin(cn)
    cn.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
