# 1 Dependent ROS 2 packages
- `Gazebo` :
```bash
	sudo apt install ros-humble-gazebo-*
```
- `Cartographer` : 
```bash
	sudo apt install ros-humble-cartographer
	sudo apt install ros-humble-cartographer-ros
```

> [!summary] Cartographer được sử dụng để xây dựng bản đồ và định vị robot trong realtime

- `Navigation 2` : 
```bash
	sudo apt install ros-humble-navigation2
	sudo apt install ros-humble-nav2-bringup
```
# 2 TurtleBot3 packages
```bash
	source ~/.bashrc
	sudo apt install ros-humble-dynamixel-sdk
	sudo apt install ros-humble-turtlebot3
	sudo apt install ros-humble-turtlebot3-msgs
	sudo apt install ros-humble-turtuebot3-gazebo
```

> [!summary] `dynamixel-sdk` là package dùng để điều khiển và giao tiếp với các động cơ

> [!note] Để tăng khả năng tùy chỉnh thì không cần thiết phải install rồi source underlay 

## 1. Setup enviroment

```bash
	echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
	echo "source /usr/share/gazebo/setup.bash" >> ~/.bashrc
	echo "export TURTLEBOT3_MODEL=waffle" >> ~/.bashrc
```