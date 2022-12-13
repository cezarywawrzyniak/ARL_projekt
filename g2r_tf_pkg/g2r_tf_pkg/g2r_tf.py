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

from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from nav_msgs.msg import Odometry



class G2r_tf_node(Node):

    def __init__(self):
        super().__init__('g2r_tf_node')
        self.odom_sub = self.create_subscription(Odometry, '/repeater/tello1/pose/info', self.odom_callback, 10)
        self.tf_broadcaster = TransformBroadcaster(self)


    def odom_callback(self, odom_msg):

        t = TransformStamped()

        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'base_link_1'
        t.child_frame_id = 'world'

        t.transform.translation.x = odom_msg.pose.pose.position.x
        t.transform.translation.y = odom_msg.pose.pose.position.y
        t.transform.translation.z = odom_msg.pose.pose.position.z


        t.transform.rotation.x = odom_msg.pose.pose.orientation.x
        t.transform.rotation.y = odom_msg.pose.pose.orientation.y
        t.transform.rotation.z = odom_msg.pose.pose.orientation.z
        t.transform.rotation.w = odom_msg.pose.pose.orientation.w

        self.tf_broadcaster.sendTransform(t)
        
def main(args=None):
    rclpy.init()

    g2rtf = G2r_tf_node()
    
    rclpy.spin(g2rtf)
    g2rtf.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
