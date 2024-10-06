
## 1. Tutorial
- Step 1: Tạo workspace `simple_pubsub` và package `cpp_pubsub` :

```bash
	# Tạo workspace
	mkdir -p simple_pubsub/src && cd simpe_pubsub/src
	# Tạo package
	ros2 pkg create --build-type ament_cmake cpp_pubsub
```

- Step 2: Clone source code của publisher node và subscriber node:

```bash
	# Publisher node
	wget -O publisher_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_publisher/member_function.cpp
	# subscriber node
	wget -O subscriber_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_subscriber/member_function.cpp
```

> [!question] Giải thích cmd trên:
> - `wget` : Cmd để tại tệp từ web xuống
> - `-O publisher_memmber_function.cpp` : Tham số `-o` để đổi tên cho tệp được tải xuống
> - `https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_publisher/member_function.cpp` : Vị trí của tệp cần tải xuống

- Step 3: Config package

> [!important] Để config cho một cpp package cần thực hiện các bước sau:
> - Step 1: [[Cấu hình `package.xml` để khai báo thông tin của package như dependencies cho ROS2 quản lý]]
> - Step 2: [[Cấu hình `CMakeLists.txt` phục vụ cho việc build ROS2 package]]

- Step 4: Build and run nodes

```bash
	# From src of workspace
	colcon build --packages-select cpp_pubsub

	# Terminal 1
	source install/setup.bash
	ros2 run cpp_pubsub  talker

	# Terminal 2
	source install/setup.bash
	ros2 run cpp_pubsub listener
```

## 2. Advanced

> [!question] Problem: Vẫn yêu cầu trên nhưng tự code lại source code cho các nodes

