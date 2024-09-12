- `source` là lệnh thực thi script shell file. Ví dụ: `.bash`, `.sh`, ...
- **rqt**: GUI tools for ROS2

- `list` cmd to see nodes and their associated topics, services, action, ...
```bash
	ros2 node list
	ros2 topic list
	ros2 service list
	ros2 action list
	ros2 param list
```
- List of executables packages:
```bash
	ros2 pkg executables <package_name>
```

# 1 Node
- Cmd run 1 node:
```bash
	ros2 run <pkg_name> <executable_name>
```
- Ví dụ: 
```bash
	ros2 run turtlesim turtlesim_node
```
- Check info của 1 node:
```bash
	ros2 node list # Liệt kê các nodes hiện có

	ros2 node info <node_name> # Sử dụng tên được liệt kê khi sử dụng node list
```

# 2 Topic

```bash
	ros2 topic list # Liệt kê các topics hiện có

	ros2 topic echo <topic_name> # Xem data đang được published bởi topic

	ros2 topic info <topic_name> # Xem info của topic ví dụ: Type, publisher count, subscription count
```

# 3 Service

# 4 Action

# 5 Parameter

# 6 Launching nodes
```bash
	ros2 launch turtlesim multisim.launch.py # File turtlesim/launch/multisim.launch.py will be runned by command
```