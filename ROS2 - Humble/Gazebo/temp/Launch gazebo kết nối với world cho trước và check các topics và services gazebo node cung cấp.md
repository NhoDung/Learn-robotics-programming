- Step 1: Launch world file có đường dẫn `~/Desktop/test.world`

```bash
	ros2 launch gazebo_ros gazebo.launch.py world:=$HOME/Desktop/test.world 
```

> [!warning] Trong ROS2 ta không dùng được `~` mà cần thay bằng biến `$HOME`

- Step 2: Sử dụng rqt_graph để check node và list để check topics và services


- Step 3: Test service call

```bash
	# Set entity state with position
	ros2 service call /set_entity_state gazebo_msgs/srv/SetEntityState "{state: {name: 'unit_box', pose: {position: {x: 0.0, y: 0.0, z: 0.0}}}}"
```


```bash
	# Set entity state with twist
	ros2 service call /set_entity_state gazebo_msgs/srv/SetEntityState "{state: {name: 'unit_box', twist: {linear: {x: 12.0, z: 12.0}, angular: {z: 10.0}}}}"
```
