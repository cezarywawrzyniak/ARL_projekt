#!/bin/bash

export GAZEBO_MODEL_PATH=${PWD}/install/tello_gazebo/share/tello_gazebo/models
export GAZEBO_MODEL_DATABASE_URI=
source /usr/share/gazebo/setup.sh
ros2 launch tello_gazebo simple_launch.py
