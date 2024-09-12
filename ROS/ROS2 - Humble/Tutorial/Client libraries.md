- We will use `colcon` to create and build ROS2 workspace
- `colcon` : Bản cải tiến (iteration) của các ROS build tool như `catkin_make`, `catkin_make_isolated`, `catkin_tool`

# 1 Build workspace
- Do build types ví dụ như `ament_cmake` không hỗ trợ khái niệm `devel` space và yêu cầu các pkg phải được cài đặt.
- Option `--symlink-install` cho phép các installed files được thay đổi khi các file trong `src` space thay đổi
```bash
	colcon build --symlink-install
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

# 3 Creating package
- Từ trong `src` folder chạy cmd sau:
```bash
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 <package_name> # nếu dùng ament_python thì thay ament_cmake
```
- Để tạo node thì chạy cmd sau:
```bash
	ros pkg create --build-type ament_cmake --license Apache-2.0 --node-name <my_node> <my_package>
```
- Để build một package cụ thể:
```bash
	colcon build --packages-select my_package
```