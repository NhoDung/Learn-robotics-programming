- Step 1: Setup ROS 2 environment (Nếu đã source từ trước rồi thì bỏ qua)
```bash
	echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
	
	source ~/.bashrc
```
- Step 2: Create workspace
```bash
	mkdir -p ~/Documents/GitHub/robotics-programming/turtlebot3_ws/src
	cd ~/Documents/GitHub/robotics-programming/turtlebot3_ws/src
	# clone turtlebot3 packages
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/DynamixelSDK.git
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/turtlebot3.git
	# clone simulation packages
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
	# back to root of workspace
	cd ../
	# build workspace
	colcon build --symlink-install
```
- Step 3: Build workspace (Mỗi khi thay đổi workspace thì phải build lại)
```bash
	# Nếu ram nhiều thì build trực tiếp (Khoảng 16GB RAM)
	colcon build --symlink-install
```

```bash
	# Nếu ram ít thì build lần lượt từng package bằng cmd sau
	colcon build --packages-select <package_name>
	# Note: Nếu báo thiếu package nào thì build package đấy
```
- For example:
```bash
	colcon build --packages-select dynamixel_sdk
	# turtlebot3_msgs
	colcon build --packages-select turtlebot3_msgs
	# turtlebot3
	colcon build --packages-select turtlebot3_cartographer
	colcon build --packages-select turtlebot3_description
	colcon build --packages-select turtlebot3_navigation2
	colcon build --packages-select turtlebot3_teleop
	colcon build --packages-select turtlebot3_example
	colcon build --packages-select turtlebot3_node
	colcon build --packages-select turtlebot3_bringup
	colcon build --packages-select turtlebot3
	# simulation
	colcon build --packages-select turtlebot3_gazebo
	colcon build --packages-select turtlebot3_fake_node
	colcon build --packages-select turtlebot3_simulations
```
- Step 4: Setup environment
```bash
	# 
	echo "source ~/Documents/GitHub/robotics-programming/turtlebot3_ws/install/setup.bash" >> ~/.bashrc
	# Gazebo path
	echo "source /usr/share/gazebo/setup.sh" >> ~/.bashrc
	# Export turtlebot3 model
	echo "export TURTLEBOT3_MODEL=waffle" >> ~/.bashrc
	# Run in 1 command by source .bashrc
	source ~/.bashrc
```

# 1 Simulation world
- Open new terminal to launch simulation world
```bash
	# run simulation world
    ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
```
- Open new terminal to launch teleop node
```bash
	ros2 run turtlebot3_teleop teleop_keyboard
```
# 2 SLAM
- Open new terminal to launch slam node
```bash
	ros2 launch turtlebot3_cartographer cartographer.launch.py use_sim_time:=True
```
- Use teleop node to discover map
- Open new terminal to save map
```bash
	ros2 run nav2_map_server map_saver_cli -f ~/Documents/GitHub/robotics-programming/turtlebot3_ws/src/map
```

# 3 Navigation
- Open new terminal to launch navigation node using saved map in SLAM
```bash
	ros2 launch turtlebot3_navigation2 navigation2.launch.py map:=$HOME/Documents/GitHub/robotics-programming/turtlebot3_ws/src/map.yaml
```
- In Rviz, estimate initial pose and set goal pose