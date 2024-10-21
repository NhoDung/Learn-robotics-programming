
## 1. Tutorial
- Step 1: Tạo workspace `simple_pubsub` và package `cpp_pubsub` :

```bash
	# Tạo workspace
	mkdir -p simple_pubsub/src && cd simpe_pubsub/src
	# Tạo package
	ros2 pkg create --build-type ament_cmake cpp_pubsub
```

- Step 1: (Optional) Tạo workspace như trên và mở VS Code :
```bash
	# Tạo workspace và mở vs code
	mkdir simple_pubsub && cd simple_pubsub && code .
	# Tạo src folder
	mkdir src && cd src
	# Tạo package 
	ros2 pkg create --build-type ament_cmake cpp_pubsub
```

- Step 2: Clone source code của publisher node và subscriber node:

```bash
	# Sau khi create package ta đang đứng ở src of root workspace nên cần chuyển đến src folder của package
	cd cpp_pubsub/src
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
	# Back to root of workspace and build
	colcon build --packages-select cpp_pubsub

	# Terminal 1
	source install/setup.bash
	ros2 run cpp_pubsub  talker

	# Terminal 2
	source install/setup.bash
	ros2 run cpp_pubsub listener
```

> [!question] Sau khi build project thì các executables được lưu ở đâu ?

## 2. Advanced

> [!question] Problem: Vẫn yêu cầu trên nhưng tự code lại source code cho các nodes để hiểu code

> [!done] Các bước cơ bản để viết publisher node
> - Step 1: Khởi tạo node
> - Step 2: Tạo publisher với topic cho trước
> - Step 3: Tạo một timer sau một chu kỳ gọi tới một callback function
> - Step 4: Định nghĩa callback function để publish message và log ra terminal

> [!done] Các bước cơ bản đề viết subscriber node
> - Step 1: Khởi tạo node
> - Step 2: Tạo subscriber với topic cho trước và gọi tới một callback function mỗi khi có message
> - Step 3: Định nghĩa callback function để mỗi khi nhận được message sẽ log ra terminal

