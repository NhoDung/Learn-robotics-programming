#!/bin/bash

# Set locale
locale  # check for UTF-8
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8 && sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 && export LANG=en_US.UTF-8
locale  # verify settings

# Set source
sudo apt install software-properties-common && sudo add-apt-repository universe
sudo apt update && sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Install ROS
sudo apt update && sudo apt upgrade -y
sudo apt install -y ros-humble-desktop ros-dev-tools

# Add source env to .bashrc
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

# ROS manage tools
sudo apt update
sudo apt install -y ~nros-humble-rqt* python3-rosdep python3-colcon-common-extensions
sudo apt install -y ros-humble-rviz2 ros-humble-turtle-tf2-py ros-humble-tf2-ros ros-humble-tf2-tools ros-humble-turtlesim

# Gazebo pkg
sudo apt install ros-humble-gazebo-*
# Cartographer pkg
sudo apt install ros-humble-cartographer ros-humble-cartographer-ros
# Navigation 2 pkg
sudo apt install ros-humble-navigation2 ros-humble-nav2-bringup

# Gazebo simulation
sudo apt install -y gazebo
