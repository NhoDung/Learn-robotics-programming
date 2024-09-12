# 1 Plugin 101
- **Plugin:** A chunk of code (1 đoạn code) được compiled as a shared libraries và insert vào simulation. Plugin có thể truy cập trực tiếp vào mọi chức năng của gazebo thông qua standard C++ classes (lớp c++ tiêu chuẩn)
- Plugin rất hữu dụng vì:
	- Let developer control gần như tất cả các khía cạnh của gazebo
	- Là các self-contained routines (quy trình tự chứa) rất dễ dàng để chia sẻ
	- Có thể được insert or remove khỏi hệ thống đang chạy
- Những phiên bản gazebo trước dùng controller nhưng được biên dịch tĩnh và vì thế không linh hoạt bằng plugin. Plugin cho phép user có thể tùy chọn chức năng nào cho simulation
- Nên sử dụng plugin khi:
	- Thay đổi simulation bằng lập trình. Ví dụ:
		- Move models
		- Respond to events
		- Insert model được cho bởi 1 tập các preconditions (điều kiện tiên quyết)
	- Muốn fast interface to gazebo mà không có độ trễ truyền thông. Ví dụ:
		- Không tuần tự hóa các messages
		- Giải tuần tự hóa các messages
	- Muốn chia sẻ code của bản thân cho người khác
## 1.1 Plugin types
- Có 6 loại plugins
	- World
	- Model
	- Sensor
	- System
	- Visual
	- GUI
- Mỗi loại plugin được quản lý và điều hành bởi các thành phần khác nhau của gazebo. Ví dụ:
	- Model plugin: Được đính kèm vào và điều khiển 1 model cụ thể trong gazebo
	- World plugin: Được đính kèm vào world
	- Sensor plugin: Được đính kèm vào 1 sensor cụ thể
	- System plugin: Được chỉ định thông qua cmd line và chạy đầu tiên khi gazebo startup -> Cho phép user kiểm soát quá trình khởi động
- Plugin nên được chọn dựa vào chức năng mong muốn. Ví dụ:
	- Sử dụng world plugin để control world properties như physics engine, ambient lighting, ...
	- Sử dụng model plugin để control joint and state of a model
	- Sử dụng sensor plugin để thu thập dữ liệu từ cảm biến và control sensor properties

## 1.2 Hello world plugin

### 1.2.1 Code explained


## 1.3 Compiling the plugin
- Step 1: Sử dụng `CMakeLists.txt`
- Step 2: Build plugin:
```bash
	# Create build folder
	mkdir build && cd build
	# Complie code
	cmake ../ && make 
```
- Sau khi compile sẽ trả về 1 shared libraries có dạng `build/my_plugin.so`

## 1.4 Using the plugin
- Mỗi khi compile xong thì có thể đính kèm nó vào world hoặc model trong `.sdf` file
- Khi startup:
	- Gazebo parses SDF file (phân tích file)
	- Gazebo locates plugin and loads code
> Note: Điều quan trọng là Gazebo phải có khả năng tìm được plugin hoặc được path to plugin đầy đủ được chỉ định hoặc plugin tồn tại trong các paths in `GAZEBO_PLUGIN_PATH` environment variable
- Create a world file and attack compiled file
```xml
	<?xml version="1.0"?>
	<sdf version="1.4">
	  <world name="default">
	    <plugin name="hello_world" filename="libhello_world.so"/>
	  </world>
	</sdf>
```


# 2 Model plugins

# 3 World plugins

# 4 Programmatic world control

# 5 System plugins