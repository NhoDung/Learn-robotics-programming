---
~
---
> [!abstract] Ý nghĩa các package con của `Nav2`
> - `nav2_bringup` : Chứa launch file cho nav2 or turtlebot 3
> - `nav2_map_server` & `nav2_amcl` : Dùng để quản lý map và estimate pose trong map
> - `nav2_planner` & `nav2_controller` : Là các task server chứa các interface quan trọng như: `ComputePathToPose` và `FollowPath`
> - `nav2_core` : Triển khai các task server cơ bản và các plugin đi kèm

## 1. `nav2_core`

> [!info] `nav2_core` : là package chứa các abstract interface để triển các khai các plugins
> - Global planner: 
> - Controller: 
> - Smoother: 
> - Goal checker: 
> - Behavior:
> - Progress checker: 
> - Waypoint task executor 
> - Exception in planning and controlling

- Các plugin được hosted bởi các Task Server để handle các requests và các algorithm plugins instances

## 2. `nav2_bringup`

> [!info] `nav2_bringup` là package chứa các file launch mẫu để dễ dàng triển khai Nav2

## 3. `nav2_map_server`

> [!info] `nav2_map_server` dùng để cung cấp map tới phần còn lại của Nav2 system. Map server có thể:
> - Cung cấp map khi node bringup
> - Thay đổi map bằng `load_map` service ngay trong runtime
> - Save map bằng cách sử dụng `save_map` server

- Nav2 map server hỗ trợ nhiều map types hơn so với ROS1 navigation map server
	- Occupancy Grid (`nav_msgs/OccupancyGrid`) : Map lưới. Hỗ trợ với các file như PNG, BMP hoặc JPEG đi kèm file `.yaml` mô tả resolution, gốc tọa độ, ...
	- Costmap
	- Map 3D (Chưa tìm hiểu tới)

- Map server chia làm 3 phần:
	- `map_server` : Phụ trách load map thông qua CLI or service request
	- `map_saver` : Phụ trách save map thông qua CLI or service request
	- `map_io` : Là một map input-output library. Được thiết kế là một đối tượng độc lập để cho phép dễ dàng save/load map từ code bên ngoài chỉ cần thông qua một calling function

- API function mà `map_io` cung cấp:
	- `loadMapYaml()` để load yaml file
	- `loadMapFromFile()` để load image from map file và generate ra OccupancyGrid
	- `loadMapFromYaml()` để load map YAML, image from map file và generate ra OccupancyGrid
	- `saveMapToFile()` để ghi OccupancyGrid ra file


> [!abstract] Những gì có thể làm được với map server
> - Để load map có thể add trực tiếp thông qua cmd hoặc thêm vào file `map_server_params.yaml`
> - Có thể cấu hình maps khác nhau cho nhiều map server khác nhau trong cùng một file cấu hình
> - Hiện tại chỉ hỗ chợ OccupancyGrid map

## 4. `nav2_amcl`

> [!info] `nav2_amcl` là một module để xác định pose (position và orientation) của robot trong một map cho trước

> [!abstract] AMCL - Adaptive Monte Carlo Localization
> - Đây là một probabilistic localization module (module vị trí dựa trên xác suất) 
> - Vị trí được ước tính trên map cho trước bằng cách sử dụng một 2D laser scanner

## 5. `nav2_planner`

> [!info] `nav2_planner` là một Task Server triển khai `nav2_behavior_tree::ComputePathToPose` interface

> [!warning] TODO: `Tìm hiểu về task server`

- Interface `nav2_behavior_tree::ComputePathToPose` chịu trách nhiệm tạo ra một feasible path từ điểm start and end robot poses
- Ngoài ra interface còn chịu trách nhiệm load các planner plugin

> [!important] Note: `Có thể sử dụng planner plugin để viết thuật toán nhưng chỉ việc được bằng C++`

## 6. `nav2_controller`

> [!info] `nav2_controller` là một Task Server triển khai `nav2_msgs::action::FollowPath` interface


## 7. `nav2_bt_navigator`

