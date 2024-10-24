> [!important] Nếu chạy cùng 1 node 2 lần trong ros2 thì sẽ tạo ra 2 node cùng tên

## 1. Cách 1: Sử dụng remapping 

> [!info] Remapping là tham số để tái gán node properties như: node names, topic names, service name, ...

Ví dụ:

```bash
	# Terminal 1 
	ros2 run turtlesim turtlesim_node

	# Terminal 2
	ros2 run turtlesim turtlesim_node --ros-args --remap __node:=my_turtle
```

> [!done] Khi chạy 2 cmd trên sẽ tạo ra 2 node GUI turtlesim_node


## 2. Cách 2: Sử dụng `/spawn` serivce

> [!attention] Nếu chưa biết cách sử dụng cmd `service call` thì có thể dùng `rqt` để call service

> [!question]- Khi run `rqt` hoặc `rqt_graph` thì tool này giao tiếp với ROS2 graph như thế nào ?
> - `rqt` hoặc `rqt_graph` khi chạy thực chất là 1 node trong ros2 graph

- Step 1: Run turtlesim_node và rqt
```bash
	# Terminal 1
	ros2 run turtlesim turtlesim_node

	# Terminal 2
	rqt
```
- Step 2: Trên GUI của rqt:
	- Chọn `/spawn` service
	- Set property: `{x: 1.0, y: 1.0, theta: 0.0, name: "turtle2"}`
	- Nhấn `call` -> Check trên GUI turtlesim_node xem đã có thêm 1 turtle hay chưa

---

 > [!todo] Hoàn thiện nốt tutorial sử dụng cmd để call `/spawn` service
 
 