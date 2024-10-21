## 1. Tutorial

> [!abstract] Ta sẽ tạo 2 node gồm service và client với interface type được định nghĩa sẵn trong package `example_interface`

- Step 1: Tạo workspace `simple_srv` và package `srv_by_cpp` có add sẵn các dependencies :

```bash
	ros2 pkg create --build-type ament_cmake srv_by_cpp --dependencies rclcpp example_interfaces
```

- Step 2: [[Write service node and client node]]

- Step 3: Config `CMakeLists.txt` to add executables

```cmake
	add_executable(server src/add_two_ints_server.cpp)
	ament_target_dependencies(server rclcpp example_interfaces)
	
	add_executable(client src/add_two_ints_client.cpp)
	ament_target_dependencies(client rclcpp example_interfaces)
	
	install(TARGETS
	  server
	  client
	  DESTINATION lib/${PROJECT_NAME})
```

- Step 4: Build and run nodes:

```bash
	colcon build

	# Terrminal 1
	source install/setup.bash
	ros2 run srv_by_cpp server

	# Terminal 2
	source install/setup.bash
	ros2 run srv_by_cpp client 1 2
```

## 2. Advanced

> [!question] Problem: [[Sử dụng lại service type trên để viết một service trả về tích của hai số nguyên]]



