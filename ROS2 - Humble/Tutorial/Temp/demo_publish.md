- Sử dụng cmd `ros2 topic pub`
```bash
	ros2 topic pub /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

> [!check] Giải thích tạo sao các cmd gần giống nhau nhưng cái chạy được cái không ?

```bash
	# Cmd chạy được
	ros2 topic pub /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
	# Cmd chạy được
	ros2 topic pub /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear:{x: 2.0,y: 0.0,z: 0.0},angular:{x: 0.0,y: 0.0,z: 1.8}}"
	# Cmd không chạy được
	ros2 topic pub /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear:{x:2.0,y:0.0,z:0.0},angular:{x:0.0,y:0.0,z:1.8}}"
```

> [!check] Bán kính đường tròn của turtle trong cmd trên là bao nhiêu ?

> [!question] Problem : Cho turtle chạy lại với bán kính = 2 ?

