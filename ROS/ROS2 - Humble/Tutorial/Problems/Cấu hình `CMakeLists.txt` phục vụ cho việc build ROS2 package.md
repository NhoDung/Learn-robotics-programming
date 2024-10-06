
> [!important] Các bước cần có để viết `CMakeLists.txt` :
> - Step 1: Khai báo chung: cmake version, package name, compiler, ...
> - Step 2: Tìm và add các dependencies
> - Step 3: Thêm các executables sau đó install chúng
> - Step 4: Kết thúc tệp CMake

- Tìm và add các dependencies:

```CMake
	find_package(ament_cmake REQUIRED)
	find_package(rclcpp REQUIRED)
	find_package(std_msgs REQUIRED)
```

- Thêm các executables sau đó install chúng

```CMake
	# Add executable with name talker
	add_executable(talker src/publisher_member_function.cpp)
	ament_target_dependencies(talker rclcpp std_msgs)

	# Add executable with name listener
	add_executable(listener src/subscriber_member_function.cpp)
	ament_target_dependencies(listener rclcpp std_msgs)

	# Install executables
	install(TARGETS
		talker
		listener
		DESTINATION lib/${PROJECT_NAME})
```

- Kết thúc `CMakeLists.txt` (Để dòng code ở cuối file)

```CMake
	ament_package()
```
