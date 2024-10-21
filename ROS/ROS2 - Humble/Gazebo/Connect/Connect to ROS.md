# 1 Overview of ROS2 integration

# 2 Installing gazebo_ros_pkgs (ROS2)
- Set of ROS2 pkg to interface with gazebo được chứa trong 1 meta pkg named `gazebo_ros_pkgs`


# 3 Using `ros2 launch`

## 1. Using `ros2 launch` to open world models


## 2. Creating your own Gazebo ROS package


### 2.1. Creating custom world file

### 2.2. Editing world file in gazebo





---
## 3. Gazebo - ROS package

> [!info] Để connect giữa ROS2 và Gazebo ta sử dụng meta-package `gazebo_ros_pkgs`. Trong package này bao gồm các package con:
> - `gazebo_ros` : 
> - `gazebo_msgs` : 
> - `gazebo_ros_control` :
> - `gazebo_plugins` :

> [!abstract] Cách kết nối giữa ROS2 và Gazebo:
> - Launch gzserver và các [[system plugins]] của Gazebo trong package gazebo_ros để thực hiện kết nối giữa Gazebo và ROS2 
> - Sau khi launch, Gazebo đóng vai trò là một node trong ROS2 graph
> - Các topics và services mà gazebo cung cấp sẽ tùy vào plugins được thêm vào
> 	- System plugins:
> 	- World plugins:
> 	- Model plugins:


> [!question] Example: [[Launch gazebo kết nối với world cho trước và check các topics và services gazebo node cung cấp]]

