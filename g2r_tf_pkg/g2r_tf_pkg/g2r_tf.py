from tello_msgs.srv import TelloAction
from tello_msgs.msg import TelloResponse
from tello_interface.srv import TelloState
from ros2_aruco_interfaces.msg import ArucoMarkers
from geometry_msgs.msg import PoseArray, Pose
import math
import numpy as np
import time
from enum import Enum
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
import rclpy
from rclpy.node import Node

from std_msgs.msg import Empty

from math import sqrt

from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from nav_msgs.msg import Odometry
from tf2_ros.buffer import Buffer
from tf2_ros import TransformListener


def quaternion_from_euler(ai, aj, ak):
    ai /= 2.0
    aj /= 2.0
    ak /= 2.0
    ci = math.cos(ai)
    si = math.sin(ai)
    cj = math.cos(aj)
    sj = math.sin(aj)
    ck = math.cos(ak)
    sk = math.sin(ak)
    cc = ci*ck
    cs = ci*sk
    sc = si*ck
    ss = si*sk

    q = np.empty((4, ))
    q[0] = cj*sc - sj*cs
    q[1] = cj*ss + sj*cc
    q[2] = cj*cs - sj*sc
    q[3] = cj*cc + sj*ss

    return q


class G2r_tf_node(Node):

    def __init__(self):
        super().__init__('g2r_tf_node')
        self.odom_sub = self.create_subscription(Odometry, '/repeater/tello_1/pose/info', self.odom_callback, 5)
        self.tf_broadcaster = TransformBroadcaster(self)
        print("Node started!")
        self.tf_static_broadcaster = StaticTransformBroadcaster(self)
        self.make_transforms("map", "world",0,0,0)
        # self.make_transforms("world", "odom",0,0,0)  
        self.make_transforms("odom", "base_link_1",(np.pi/2),np.pi,(np.pi/2))
        


    def odom_callback(self, odom_msg):
        # print("idzie")
        t = TransformStamped()

        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'world'
        
        t.child_frame_id = 'odom'

        t.transform.translation.x = odom_msg.pose.pose.position.x
        t.transform.translation.y = odom_msg.pose.pose.position.y
        t.transform.translation.z = odom_msg.pose.pose.position.z


        t.transform.rotation.x = odom_msg.pose.pose.orientation.x
        t.transform.rotation.y = odom_msg.pose.pose.orientation.y
        t.transform.rotation.z = odom_msg.pose.pose.orientation.z
        t.transform.rotation.w = odom_msg.pose.pose.orientation.w
        # print(t.transform.translation.x)

        self.tf_broadcaster.sendTransform(t)


    def make_transforms(self, header_name, child_name, x, y,z):
        t = TransformStamped()

        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = header_name
        t.child_frame_id = child_name

        t.transform.translation.x = 0.0
        t.transform.translation.y = 0.0
        t.transform.translation.z = 0.0
        quat = quaternion_from_euler(x, y, z)
        t.transform.rotation.x = quat[0]
        t.transform.rotation.y = quat[1]
        t.transform.rotation.z = quat[2]
        t.transform.rotation.w = quat[3]
        # print(t)

        self.tf_static_broadcaster.sendTransform(t)     

def main(args=None):
    rclpy.init()

    g2rtf = G2r_tf_node()
    
    rclpy.spin(g2rtf)
    g2rtf.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
