> [!tip] Node trong ROS2 là gì?
> - Node là thành phần trong ROS2 graph 
> - Node sử dụng [[client libraries]] để giao tiếp với nhau trên cùng process, different process or different machine
> - Node thường đóng vai trò là một computation unit trong ROS2 graph, mỗi node do one logical thing

## 1. Nodes trong ROS2 có những vai trò gì?

- Node có thể publish tới named topics để deliver (giao) data tới các nodes khác
- Node có thể subscribe tới named topics để get data từ các nodes khác
- Node có thể là một service/action server để cung cấp functionality tới các nodes khác
- Node có thể là một service/action client để giao cho nodes khác thực hiện một nhiệm vụ cụ thể
- Node có thể cung cấp configurable parameter để điều chỉnh behavior trong runtime
- Node có thể là kết hợp của các đặc điểm trên trong cùng một thời điểm
- Kết nối giữa các nodes được thực hiện thông qua một distributed discovery process

## 2. Discovery process

- Discovery process được thực hiện automatically thông qua underlying middleware of ROS2

> [!note] Tóm tắt discovery process:
> - Khi một node khởi động, nó quảng bá sự tồn tại tới các nodes khác trong network thông qua cùng ROS domain. Từ đây các nodes có thể tự phát hiện ra nhau mà không cần sự can thiệp của developer
> - Các nodes tiếp tục quảng bá định kỳ sự tồn tại tới các node khác. Nếu có node mới khác được thêm vào thì có thể connect được
> - Các nodes khi offline sẽ quảng bá lần cuối

> [!warning] Các connect chỉ được thiết lập nếu thỏa mãn Quality of Service setting

## 3. Parameter of node

> [!info] Parameter trong ROS2 là gì ?
> - Parameters được sử dụng để configure nodes khi startup và during runtime mà không cần thay đổi source code
> - Parameters được liên kết với từng node riêng lẻ
> - Lifecycle of parameter gắn liền với lifecycle of node
> - Parameters được truy cập bởi node name, node namespace, parameter name và parameter namespace. Parameter namespace là optional 

> [!info] Thành phần của parameter:
> - Mỗi parameter gồm một key, một value và một description 

