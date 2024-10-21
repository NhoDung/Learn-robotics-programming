## 1. Create a TurtleBot3 workspace

- Step 1: Create workspace

```bash
	mkdir -p turtlebot3_ws/src && cd turtlebot3_ws/src
```

- Step 2: Clone necessary packages

```bash
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/DynamixelSDK.git
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/turtlebot3.git
	git clone -b humble-devel https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
```

- Step 3: Build and source workspace

> [!note] Trong trường hợp cấu hình máy yếu thì không nên build toàn bộ dẫn đến crash mà nên build từng package một

## 2. Launch simulation world 

```bash
	ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
```

## 3. Using teleop node

```bash
	ros2 run turtlebot3_teleop teleop_keyboard
```

## 4. SLAM

- Step 1: Launch simulation world and run teleop node
- Step 2: Run SLAM node and using teleop node để quét map

```bash
	ros2 launch turtlebot3_cartographer cartographer.launch.py use_sim_time:=True
```

- Step 3: Save map

```bash
	ros2 run nav2_map_server map_saver_cli -f <path>/map
```

## 5. Navigation 

- Step 1: Launch simulation world
- Step 2: Launch navigation 

```bash
	ros2 launch turtlebot3_navigation2 navigation2.launch.py map:=<path>/map.yaml
```

- Step 3: Estimate position and set nav goal
