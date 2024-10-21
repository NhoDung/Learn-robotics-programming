

## 1. ROS 2

> [!note] 2 khái niệm của ROS 2 cần nắm là:
> - Action server
> - Lifecycle node và bond connection 

---
> [!summary] Ứng dụng của action server:
> - Action server được sử dụng để communicate với highest level Behavior Tree Navigator thông qua action message là `NavigateToPose`
> - Action server được sử dụng cho BT để communicate với action server nhỏ hơn để: compute plan, control effort và recoveries
> - ...

---
> [!summary] Công dụng của lifecycle nodes (tên gọi khác là manage nodes): 
> - Đây là các nodes chứa state machine transition (chuyển đổi máy trạng thái) để bringup (khởi động) và teardown (dừng) các ROS2 servers.
> - Điều trên giúp:
> 	- xác định behavior của ROS2 system trong khi startup và shutdown
> 	- cấu trúc program theo một số cách hợp lý





## 2. Bahavior tree

> [!note] Behavior tree ưu việt hơn so với FSM (Finite state machine) trong complex robotics tasks





## 3. Navigation servers

- Planner và controller là heart of navigation task 
- Recovery được sử dụng để get robot out of bad situation or make system fault-tolerant (có thể chịu lỗi)
- Smooother được sử dụng để cải thiện chất lượng của planned path 

> [!summary] Có tất cả 4 action servers : planner, controller, smooother và behavior 
> - Các servers này chứa một map của algorithm plugins để hoàn thành task 
> - Các servers này cũng chứa environmental representation được algorithm plugins sử dụng để compute output 


> [!abstract] Một số đặc điểm của các action servers:
> - Planner, controller và smoother servers sẽ được cấu hình khi chạy bằng tên và kiểu thuật toán được sử dụng




## 4. State estimation 




## 5. Environmental representation 

