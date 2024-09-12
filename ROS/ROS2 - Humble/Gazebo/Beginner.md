# 1 Overview and installation

# 2 Understanding GUI

# 3 Model editor

Các bước để tạo ra một simple vehicle model:
- Insert shape
- Create joint (khớp nối)
- Add sensor
- Add plugin - Để giúp model có thể tính toán, ví dụ: sensor data processing, path planning and control
	- File plugin có đuôi là `.so`
- Save model

Ngoài ra Gazebo còn có thể làm được:
- Extrude SVG file -> Để create model
- Logging and play back (Để tìm hiểu sau)
# 4 Building editor
- `Ctrl + B` để mở building editor trên gazebo

**Cách để import 1 plan**:
- Choose a `.png` image to import
- Set scale
**Cách để add feature:**
- Add wall -> Can edit
- Add window and door -> Can edit
- Add stair -> Can edit
- Add level (Thêm tầng)
- Add color and texture (Màu sắc và kết cấu)
- Save building

# 5 Quick start
- Run Gazebo
```bash
	gazebo
```
- Run Gazebo with a robot
```bash
	gazebo worlds/pioneer2dx.world # Nếu không pioneer2dx model thì gazebo sẽ tự download

	# Ngoài ra có thể xem các world đang lưu trong gazebo (Linux) bằng cách sau:
	ls /usr/share/gazebo-7/worlds # Tùy từng phiên bản đề kiểm tra
```
- Client and server separation: Khi chạy cmd `gazebo` thực chất là chạy 2 cmd sau:
	- `gzserver` : Thực thi physics update-loop and sensor data generation
	- `gzclient` : Để hiển thị GUI
```bash
	# Để chạy từng phần thì mở 2 terminal

	# terminal 1
	gzserver
	# terminal 2
	gzclient
```

# 6 Gazebo component
- World file and model file
- Environment variables:
	- `GAZEBO_MODEL_PATH` : Nơi gazebo search for model
	- `GAZEBO_RESOURCE_PATH` : Nơi gazebo search for other resources such as world and media files
	- `GAZEBO_MASTER_URI` : URI of gazebo master
	- `GAZEBO_PLUGIN_PATH` : Nơi gazebo search for thư viện chia sẻ plugin ở thời điểm runtime
	- `GAZEBO_MODEL_DATABASE_URI` : URI of online model database
	- Tất cả được bao gồm trong script sau:
```bash
	source <install_path>/share/gazebo/setup.sh
```
