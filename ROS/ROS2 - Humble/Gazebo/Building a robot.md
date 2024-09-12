# 1 Model structure and requirements
## 1.1 Overview
- Gazebo có thể dynamically load models into simulation
- Models tồn tại trên máy sau khi được download hoặc được created by you
- Model trong gazebo defines 1 physical entity với các properties:
	- Dynamic (Động). Ví dụ: Khối lượng (mass), lực ma sát, ...
	- Kinematic (Động học). Ví dụ: Giới hạn tốc độ dài, giới hạn tốc độ góc, ...
	- Visual (Trực quan). Ví dụ: Màu sắc, hình dáng, tính chất, ...
- Ngoại ra còn có thể có 1 hoặc nhiều các plugins có thể ảnh hưởng đến model's behavior
- 1 model có thể biểu diễn bất cứ thứ gì từ robot đơn giản đến phức tạp hoặc thậm chí mặt đất cũng là 1 model

## 1.2 Model database repository
```bash
	git clone https://github.com/osrf/gazebo_models
```
## 1.3 Model database structure


# 2 How to contribute a model (Chưa cần quan tâm tới)

# 3 Make a model
## 3.1 Overview
- This tutorial mô tả chi tiết về SDF Model Object
- SDF có thể mô tả từ đơn giản đến phức tạp. Tương ứng với `<model>` SDF tag
- Là collection of links, joints, collision objects (đối tượng va chạm), visual và plugins
- Tạo mô hình khó hay dễ phụ thuộc vào độ phức tạp của model mong muốn

## 3.2 Components of SDF models
- **Link**: Contains physical properties (đặc tính vật lý) of one body of the model (1 phần thân của model)
	- Nó có thể là: wheel (bánh xe) hoặc nó có thể ở trong 1 joint chaine (chuỗi khớp nối)
	- Mỗi link có thể có nhiều collision and visual elements
	- Cố gắng giảm số link trong model để cả thiện performance and stability (độ ổn định)
	- Ví dụ: 1 table model gồm 5 links (4 for legs and 1 for top)
- **Collision:** 
- **Visual:**
- **Inertial (Quán tính):** 
- **Sensor:**
- **Light:**
- **Joint**: Connect 2 links. Relationship parent-child
- **Plugin:** A shared library created by third party to control model

## 3.3 Building a model
### 3.3.1 Step 1: Collect your meshes (Thu thập lưới)
- Gathering all necessary 3D mesh file cần thiết để build model
- Gazebo cung cấp sẵn simple shape: box, sphere (hình cầu) and cylinder (hình trụ)
- Meshes có thể từ nhiều nguồn:
	- Google's 3D warehouse là 1 good repository of 3D models
	- Có thể tự tạo mesh = cách sử dụng 3D modeler như Blender or Sketchup
- Gazebo yêu cầu mesh file có format là STL, Collada or OBJ (Ưu tiên Collada or OBJ)

**Tips**: (Sau xem lại)

### 3.3.2 Step 2: Make your model SDF file


### 3.3.3 Step 3: Add to the model file

Add feature:
1. Add a link
2. Set the collision element
3. Set the visual element
4. Set the inertial properties
5. Go to #1 until all links have been added
6. Add all joints (if any)
7. Add all plugins (if any)

# 4 Make a mobile robot
## 4.1 Setup your model directory
- Create directory
```bash
	mkdir -p ~/.gazebo/models/my_robot
```
- Create a model config file
```bash
	gedit ~/.gazebo/models/my_robot/model.config
```
- Paste in the following contents
```xml
	<?xml version="1.0"?>
	<model>
	  <name>My Robot</name>
	  <version>1.0</version>
	  <sdf version='1.4'>model.sdf</sdf>
	
	  <author>
	   <name>My Name</name>
	   <email>me@my.email</email>
	  </author>
	
	  <description>
	    My awesome robot.
	  </description>
	</model>
```
- Create a `~/.gazebo/models/my_robot/model.sdf` file
```bash
	gedit ~/.gazebo/models/my_robot/model.sdf
```
- Paste in the following
```xml
	<?xml version='1.0'?>
	<sdf version='1.4'>
	  <model name="my_robot">
	  </model>
	</sdf>
```

## 4.2 Building model's structure

# 5 Import meshes

# 6 Attack meshes

# 7 Add a sensor to robot

# 8 Make a simple gripper (Tạo thanh kẹp đơn giản)

# 9 Add gripper to robot

# 10 Nested model (Các model lồng nhau)

# 11 Model editor

## 11.1 Open the model editor

## 11.2 GUI

## 11.3 Add link

## 11.4 Create joint

## 11.5 Edit your model

## 11.6 Save your model

## 11.7 Exit

## 11.8 Edit existing model


# 12 Animated box (Hộp di chuyển)
## 12.1 Setup

## 12.2 Animate box code

## 12.3 Simulate with gazebo

## 12.4 Connect to a simulation with your own executable

## 12.5 Run the simulation and connect with your own executable

## 12.6 SOURCE CODE


# 13 Make an animated model (actor)