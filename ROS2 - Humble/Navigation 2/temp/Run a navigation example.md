## 1. Tutorial 

- Step 0: Install các package cần thiết

```bash
	sudo apt install ros-humble-navigation2
	sudo apt install ros-humble-nav2-bringup
	# simulation package
	sudo apt install ros-humble-turtlebot3-gazebo
```

- Step 0+: Set environment

```bash
	source /opt/ros/humble/setup.bash 
	export TURTLEBOT3_MODEL=waffle
	export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/humble/share/turtlebot3_gazebo/models
```

> [!warning] Để đỡ phải source lại nhiều lần thì add vào `.bashrc` file

- Step 1: Run simulation

```bash
	ros2 launch nav2_bringup tb3_simulation_launch.py headless:=False
```

- Step 2: Estimate pose and test with nav goal