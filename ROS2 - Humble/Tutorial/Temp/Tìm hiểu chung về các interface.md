> [!abstract] Interface trong ROS2 là gì?
> - ROS2 applications giao tiếp với nhau thông qua một trong ba interfaces: topic, service, action
> - ROS2 sử dụng IDL (interface definition language) để mô tả các interface
> - Việc sử dụng IDL giúp ROS tools dễ generate source code cho một số language thường dùng như C++, Python, ...

> [!abstract] Support file:
> - `.msg` : Describe the fields of ROS2 message
> - `.srv` : Describe service và gồm 2 phần là `request` và `response`
> - `.action` : Describe action và gồm 3 phần là `goal`, `result` và `feedback`

## 1. Topic 

- Topic được sử dụng để send data trong network to other ROS2 nodes và không yêu cầu response 
- Topic phù hợp được sử dụng với continous data strems. Ví dụ: sensor data, robot state, ...
- Trong message ta định nghĩa được các thành phần: name, type (int, char, array, ...), default value hoặc constant

---
> [!important] Pub/Sub system là gì ?
> - A publisher/subscriber system là một system gồm các producers of data (publisher) và các consumers of data (subscriber)
> - Các publisher và subscriber connect và communicate trực tiếp với nhau thông qua một concept là "topic"
> - Khi create a publisher, ta phải gán cho nó name of topic, tương tự với khi create a subscriber
> - Số lượng publisher và subscriber là tùy thích ($0 \rightarrow \infty$) 
> - Đặc điểm: Khi một publisher publish data thì tất cả subscriber đều sẽ nhận được data đó --> Giống với bus

> [!note] Anonymous architecture in ROS2 system ?
> - Khi một subscriber receive data. Nó không cần care publisher nào đã published data (Dù có thể tìm được)
> - Ưu điểm của anonymous architecture: Các publisher và subscriber có thể được thay thế mà không làm ảnh hưởng đến hệ thống

> [!note] Strongly-typed (Kiểu dữ liệu chặt) trong ROS2 ?
> - Các kiểu dữ liệu của các fields đã được định nghĩa chặt chẽ





## 2. Service 

> [!important] Service là gì trong ROS2 ?
> - Service là một short-running remote procedure call
> - Client node sẽ make một remote procedure call tới Server node để request computation và return a result

> [!info] Thành phần của service 
> - Mỗi service được định danh bằng service name
> - Mỗi service gồm 2 parts: service server và service client 
> - Các nodes giao tiếp với nhau thông qua service message có dạng:

```IDL
	uint32 request
	---
	uint32 response
```


## 3. Action 

> [!important] Action là gì trong ROS2 ?
> - Action là một long-running remote procedure call với khả năng feedback or preempt goal (ưu tiên lại mục tiêu)

Ví dụ:
- Một high-level state machine call an action để tell navigation subsystem travel to a waypoint (điểm đích)
- Action này có thể mất vài giây hoặc vài phút để thực hiện
- Trên đường đi, navigation subsystem có thể feedback lại chẳng hạn nó đang ở bao xa
- The high-level state machine có thể dựa vào feedback để quyết định cancel or preempt the travel to waypoint 

> [!info] Các thành phần của action
> - Mỗi action được định danh bằng action name
> - Mỗi action gồm 2 parts: action server và action client
> - Các nodes giao tiếp với nhau thông action message có dạng:

```IDL
	int32 request
	---
	int32 response
	---
	int32 feedback
```

---
> [!important] Phân biệt service và action
> - Service phù hợp với các short task ($\approx ms$) và không bị ngắt giữa chừng
> - Action phù hợp với các long task ($\approx s$ or $\approx m$), có feedback liên tục khi đang thực hiện và có thể bị ngắt giữa chừng






