from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tello_controller',
            executable='controller_node',
            name='controller_node_1',
            parameters=[
            {'follow_markers': '1,3,5,7,9,21'},
            {'drone_topic': '/tello_action'},
            {'aruco_topic': '/aruco_markers_1'},
            {'position_topic': '/optitrack_topic'}
        ]
        ),
        Node(
            package='ros2_aruco',
            executable='aruco_node',
            name='aruco_node_1',
            parameters=[
            {'image_topic': '/image_raw'},
            {'camera_info_topic': '/camera_info'},
            {'poses_publisher': 'aruco_poses_1'},
            {'markers_publisher': 'aruco_markers_1'},
            {'images_publisher': 'aruco_image_1'}
        ]
        )
    ])