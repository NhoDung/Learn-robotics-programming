> [!info] Client libraries là gì trong ROS2 ?
> - CLient libraries là các APIs để implement ROS2 code cho nodes, topics, services, ...
> - Nodes viết bởi different client libraries vẫn có thể giao tiếp với nhau vì all client libraries đều implement code generator


> [!abstract] Các client libraries thường được sử dụng 
> - `rclcpp` : Nên sử dụng khi viết các node liên quan system vì giúp tăng hiệu quả của system
> - `rclpy` : Nên sử dụng khi viết các node liên quan visualization vì giúp viết nhanh và dễ viết

