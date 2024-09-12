- We will use `colcon` to create and build ROS2 workspace
- `colcon` : Bản cải tiến (iteration) của các ROS build tool như `catkin_make`, `catkin_make_isolated`, `catkin_tool`

> Note: Trong `Tutorials/Beginner: Client libraries/Using colcon to build packages` của ROS2 Humble documentation, không nên build example project vì khi install ROS2 đã install rồi nên khi build lại sẽ gây crash chương trình
# 1 Build workspace
- Trước khi build workspace thì cần resolve dependencies
- Do build types ví dụ như `ament_cmake` không hỗ trợ khái niệm `devel` space và yêu cầu các pkg phải được cài đặt.
- Option `--symlink-install` cho phép các installed files được thay đổi khi các file trong `src` space thay đổi
```bash
	colcon build --symlink-install
```
- Khi build xong thì sẽ tạo ra các folder sau:
```bash
	build install log src
```
- Sau khi đã build xong thì source environments:
```bash
	source install/setup.bash
```
- Colcon hỗ trợ nhiều kiểu build types. 2 kiểu được đề xuất là `ament_cmake` và `ament_python`
# 2 Creating workspace

Các bước gồm có:
- Source ROS2 environment
- Build workspace with colcon
- Source overlay


## 2.1 Example: Create a workspace + Clone a repository + Build
```bash
	# Step 1: Create a workspace

	# Step 2: Create src folder
	mkdir src && cd src
	# Step 3: Clone a repo to src folder
	git clone https://github.com/ros/ros_tutorials.git -b humble
	# Step 4: Back to root of ws and build
	cd ../ && colcon build
	# Step 5: Source underlay and overlay
	source /opt/ros/humble/setup.bash
	source /install/local_setup.bash
```
- Optional: Modify project to check
	- Go to `<path>/src/ros_tutorials/turtlesim/src` and open file `turtle_frame.cpp`
	- Change `setWindowTitle("TurtleSim")` to `setWindowTitle("My_TurtleSim")`
	- Rebuild workspace and source and run `turtlesim_node`
# 3 Creating package
- Từ trong `src` folder chạy cmd sau:
```bash
	# Với build tool là ament_cmake
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 <package_name> # nếu dùng ament_python thì thay ament_cmake
	# Với build tool là ament_python
	ros2 pkg create --build-type ament_python --license Apache-2.0 <package_name>
```
- Để tạo node thì thêm tham số `--node-name` bằng cách chạy cmd sau:
```bash
	# Với ament_cmake
	ros pkg create --build-type ament_cmake --license Apache-2.0 --node-name <my_node> <my_package>
	# Với ament_python
```
- Để build một package cụ thể:
```bash
	colcon build --packages-select my_package
```
- Tùy vào build tool mà folder structure sẽ khác nhau:
```bash
	# Với ament cmake
	my_package/
		CMakeLists.txt/
		include/my_package/
		package.xml
		src/
	# Với ament_python
	my_package/
		package.xml
		resource/my_package
		setup.cfg
		setup.py
		my_package/ # Không có src folder giống như trên
```
- Có thể có nhiều package trong 1 workspace và có thể từ cả 2 loại build tool
## 3.1 Example: Create a simple package with simple "Hello World" node
```bash
	# Step 1: Create workspace

	# Step 2: Create simple node + package
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 --node-name my_node my_package
	# Step 3: Build and source environment
```

## 3.2 Example: Writing a simple publisher - subscriber by C++
- **Task 1:** Create package
- **Task 2:** Write the publisher node
	- Step 1: Examine the code -> `.cpp`
	- Step 2: Add dependencies -> `package.xml`
	- Step 3: `CMakeLists.txt`
- **Task 3:** Write the subscriber node