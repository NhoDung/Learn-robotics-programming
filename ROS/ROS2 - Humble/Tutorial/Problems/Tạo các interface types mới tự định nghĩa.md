## 1. Tutorial

- Step 1: Create workspace & package `new_msgs` :

```bash
	ros2 pkg create new_msgs
```

> [!tip] Mặc định nếu không có option `--build-type` thì build type mặc định sẽ là `ament_cmake`

- Step 1+ (Option): Do folder `srv` và `include` trong package này không sử dụng đến nên có thể xóa bỏ

```bash
	rm -r create_msgs/include/ create_msgs/src/
```
- Step 2: 

```bash
	cd new_msgs && mkdir msg srv
```

- Step 3: Tạo các [[custom interface]] 
- Step 4: Configuration

```CMake
	find_package(geometry_msgs REQUIRED)
	find_package(rosidl_default_generators REQUIRED)
	
	rosidl_generate_interfaces(${PROJECT_NAME}
	  "msg/Num.msg"
	  "msg/Sphere.msg"
	  "srv/AddThreeInts.srv"
	  DEPENDENCIES geometry_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
	)
```

```XML
	<depend>geometry_msgs</depend>
	<buildtool_depend>rosidl_default_generators</buildtool_depend>
	<exec_depend>rosidl_default_runtime</exec_depend>
	<member_of_group>rosidl_interface_packages</member_of_group>
```

> [!warning] Nên để đoạn cấu hình trên sau thẻ `<test_depend>` 

- Step 5: Build and check interface

```bash
	# Build and source 
	colcon build --symlink-install && source install/setup.bash
	# Check interface
	ros2 interface show new_msgs/msg/Num && ros2 interface show new_msgs/msg/Sphere && ros2 interface show new_msgs/srv/AddThreeInts
```

