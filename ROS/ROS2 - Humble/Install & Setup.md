# 1 Requirement
- Ubuntu 22.04 - Jammy Jellyfish
# 2 Install & Setup ROS

- Set `locale` : UTF-8 support
```bash
	locale  # check for UTF-8

    sudo apt update && sudo apt install locales
    sudo locale-gen en_US en_US.UTF-8
    sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
    export LANG=en_US.UTF-8

    locale  # verify settings
```
- Add ROS 2 apt repository to your system
```bash
	# enable Ubuntu Universe repository
	sudo apt install software-properties-common
	sudo add-apt-repository universe
	# add ROS 2 GPG key with apt
	sudo apt update && sudo apt install curl -y
	sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
	# add repository to sources list
	echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
- Install ROS 2 packages
```bash
	sudo apt update && sudo apt upgrade -y
	# desktop install: ROS, RViz, demos, tutorials
	sudo apt install ros-humble-desktop
	# development tools: compilers and other tools to build ros packages
	sudo apt install ros-dev-tools
```
- Setup and configure environment
```bash
	source /opt/ros/humble/setup.bash
```

# 3 TurtleSim
- `turtlesim` : lightweight for learning ROS2
```bash
	sudo apt update && sudo apt install ros-humble-turtlesim
	# check installed
	source /opt/ros/humble/setup.bash
	ros2 pkg executables turtlesim
```

# 4 ROS 2 tools
- `rqt` : GUI tool for ROS 2 (rqt_graph. rqt_console, ...)
```bash
	sudo apt update && sudo apt install ~nros-humble-rqt*
```
- `rosdep` : dependency management utility 
```bash
	sudo apt install python3-rosdep
```
# 5 ROS 2 build tools
```bash
	sudo apt install python3-colcon-common-extensions
```
# 6 Demo

```bash
	sudo apt install ros-humble-rviz2 ros-humble-turtle-tf2-py ros-humble-tf2-ros ros-humble-tf2-tools ros-humble-turtlesim
```