## 1. Create world 

- Các map được tạo ban đầu gồm: 16x16, 8x8 và 6x6 (m)
- Do tạo quá to dẫn tới về sau lidar không thể quét hết được --> Nên lấy map 6x6 đổ xuống
- Launch world sử dụng `gazebo.launch.py`

## 2. Add turtlebot 3 to world

- 2 file launch quan trọng cần phải sử dụng lại là:
	- `spawn_turtlebot3.launch.py`: Spawn turtlebot 3 trong môi trường vừa tạo
	- `robot_state_publisher.launch.py`: Publish state of robot để có thể giao tiếp với các node khác, ví dụ như slam node

## 3. Using slam node để save map

- Sử dụng cartographer để run node quét map
- Sử dụng `nav2_map_server` để save map dưới dạng file yaml


## 4. Test with navigation 2 of turtlebot3 

- Do lỗi có liên quan đến middleware of ros2 nên cần thay thế DDS bằng Cyclone DDS. Lỗi dẫn tới amcl không để định vị vị trí của robot
- Sau khi đã khởi chạy được nav2 thì viết thêm một node để test service `navigateToPose`


## 5. Tổng kết

- Đã khởi chạy được nav2 với map mới cho turtlebot3 tuy nhiên chưa tìm được cách viết thuật toán mới bằng python
- Định hướng: Tìm hiểu thêm về cách viết các action node, composable node, ...
- Chữa cháy bằng cách sử dụng service `navigateToPose` tới các điểm theo đường thẳng
- Chưa tìm được cách viết thuật toán nào ngoài việc sử dụng plugin
- Tuy nhiên nhận thấy có thể triển khai các node hay thêm các file python vào ros2 một cách linh hoạt hơn mà không cần tuân theo việc tạo node

## 6. task

- [ ] Tạo thêm các map có dynamic obstacle
- [ ] Học khóa học để biết cách sử dụng python với nav2
