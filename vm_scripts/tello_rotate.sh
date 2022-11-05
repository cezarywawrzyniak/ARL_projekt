#!/bin/bash

ros2 service call /drone1/tello_action tello_msgs/TelloAction "{cmd: 'rc 0 0 0 0.5'}"
