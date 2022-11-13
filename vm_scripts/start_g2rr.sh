#!/bin/bash

source /opt/ros/foxy/setup.sh
cd ~/ws_g2rr
source install/setup.bash
ros2 run pkg_g2rr g2rr tello_1
