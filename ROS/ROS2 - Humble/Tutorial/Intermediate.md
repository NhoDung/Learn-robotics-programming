# 1 Managing dependencies with `rosdep`
## 1.1 What is `rosdep`
- `rosdep` : A dependency management utility (Tiện tích quản lý phụ thuộc) có thể work with packages và external libraries
- `rosdep` : A command line utility cho identifying and installing dependencies to build or install package
- `rosdep` : Không chỉ là 1 package manager mà là 1 meta-package manager
- `rosdep` thường được gọi trước khi building workspace. Được sử dụng để install các dependencies of packages trong workspace

## 1.2 Knowledge about `package.xml`

- `package.xml`: Là nơi `rosdep` finds the set of dependencies
- Bắt buộc phải liệt kê các dependencies đầy đủ và đúng, điều này cho phép tool xác định package dependencies. Nếu thiếu hoặc sai các dependencies có thể khiến user không thể sử dụng package của bạn, đóng gói workspace không theo thứ tự hoặc đóng gói không thể phát hành
- Có các loại thẻ sau:
	- `<depend>` : Các dependencies này cần được cung cấp ở cả build time và run time. Nên sử dụng với C++ package
	- `<build_depend>` : Nên sử dụng khi chỉ sử dụng 1 dependency cụ thể cho building package và không ở execution time
		- Với loại dependency này, một tệp nhị phân đã cài đặt của gói không yêu cầu gói cụ thể đó phải được cài đặt
		- Có thể gây ra vấn đề nếu gói của bạn xuất 1 tệp header có bao gồm 1 header từ phụ thuộc này
	- `<build_export_depend>` : 
	- `<exec_depend>` : Nên sử dụng cho python package
	- `<test_depend>` : 

# 2 Creating an action

# 3 Writing an action server and client
## 3.1 Creating the action package

## 3.2 Writing action server

## 3.3 Writing action client


# 4 Writing a composable node by C++ - Viết node có thể cấu hình

# 5 Example: Composing multiple nodes in a single process


# 6 Launch
- Launch system in ROS2 giúp user mô tả configuration of system và thực thi theo mô tả
- Configuration includes:
	- What program to run ?
	- Where to run ?
	- What arguments to pass them ?
	- ROS-specific convention (Quy ước đặc thù của ROS) - Giúp dễ dàng tái sử dụng component trong system bằng cách cho chúng các different configurations
- Launch files có thể được viết bằng `Python`, `XML` or `YAML` có thể start và stop different nodes như trigger và phản ứng với various events (các sự kiện khác nhau)

## 6.1 Task: Creating launch file
- Step 1: Setup
```bash
	Create new directory to store launch files
	mkdir launch
```
- Step 2: Write launch file
- Step 3: Run launch file
```bash
	# Cách 1: Go to launch directory 
	cd launch && ros2 launch turtlesim_mimic_launch.py

	# Cách 2: Run directly launch file provided by a package
	ros2 launch <package_name> <launch_file_name>
	# Lưu ý để sử dụng được cách 2 thì cần add <exec_depend> to package.xml
	# <exec_depend>ros2launch</exec_depend>
```

## 6.2 Task: Integrating launch file into ROS 2 package
- Step 1: Create package
- Step 2: Create `launch` folder on the top-level of package and enabling colcon to locate and utilize launch files
	- Python package: Include all launch file into `data_files` in `setup.py`
	- C++ package: Install all launch file in `CMakeLists.txt`
```python
	import os
	from glob import glob
	# Other imports ...
	
	package_name = 'py_launch_example'
	
	setup(
	    # Other parameters ...
	    data_files=[
	        # ... Other data files
	        # Include all launch files.
	        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*')))
	    ]
	)
```

```CMake
	# Install launch files.
	install(DIRECTORY
	  launch
	  DESTINATION share/${PROJECT_NAME}/
	)
```
- Step 3: Write launch file
- Step 4: Building and run launch file


## 6.3 Task: Using subsituations
- Launch file được sử dụng để start nodes, services và execute processes -> Những actions này đôi khi có thể có tham số và ảnh hưởng đến behavior
- Subsituations được sử dụng trong tham số để cung cấp hơn nữa sự linh hoạt khi mô tả reusable launch files
- Subsituations là các variables chỉ được đánh giá trong suốt thời gian thực thi của launch description và có thể được sử dụng để thu thập thông tin cụ thể như launch configuration, environment variable or to 



