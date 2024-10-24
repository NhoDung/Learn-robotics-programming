## 1. Tutorial 

- Step 1: Tạo workspace `simple_pubsub_py` và package `py_pubsub` :

```bash
	# Tạo workspace và mở vs code
	mkdir simple_pubsub_py && cd simple_pubsub_py && code .
	# Tạo src folder 
	mkdir src && cd src
	# Tạo python package
	ros2 pkg create --build-type ament_python py_pubsub
```

- Step 2: Clone source code của publisher và subscriber node:

```bash
	# cd đến src folder của package
	cd py_pubsub/py_pubsub
	# Clone publisher node
	wget https://raw.githubusercontent.com/ros2/examples/humble/rclpy/topics/minimal_publisher/examples_rclpy_minimal_publisher/publisher_member_function.py
	# Clone subscriber node
	wget https://raw.githubusercontent.com/ros2/examples/humble/rclpy/topics/minimal_subscriber/examples_rclpy_minimal_subscriber/subscriber_member_function.py
```

> [!note] `src` folder của python package để tên giống package

- Step 3: Config package

> [!important] Để config một python package cần thực hiện các bước sau:
> - Step 1: [[Cấu hình `package.xml` để khai báo thông tin của package như dependencies cho ROS2 quản lý]]
> - Step 2: [[Cấu hình `setup.py` phục vụ cho việc build ROS2 package]]
> - Step 3: Cấu hình `setup.cfg` về metadata của package


- Step 4: Build and run nodes

```bash
	# Back to root of workspace and build
	colcon build --package-select py_pubsub

	# Terminal 1
	source install/setup.bash
	ros2 run py_pubsub talker

	# Terminal 2
	source install/setup.bash
	ros2 run py_pubsub listener
```

## 2. Advanced


> [!question] Problem: Vẫn yêu cầu trên nhưng tự code lại source code cho các nodes để hiểu code

