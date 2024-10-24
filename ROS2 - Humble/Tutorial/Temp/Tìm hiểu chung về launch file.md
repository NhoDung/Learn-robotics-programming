> [!note] Tại sao cần launch ?
> - A ROS2 system thường gồm nhiều nodes và run trên nhiều processes (thậm chí là nhiều machines)
> - Có thể chạy lần lượt từng nodes nhưng khi nhiều nodes lên sẽ rất phức tạp

> [!abstract] Launch system in ROS2
> - Launch system được thiết kế để tự động run nhiều nodes trong một single command 
> - Launch system giúp user describe the configuration of system và thực thi nó theo described
> - The configuration gồm:
> 	- What programs to run ?
> 	- Where to run these program ?
> 	- What arguments to pass 
> 	- ROS-specific convention
> - Điều này giúp dễ tái sử dụng các components trong system bằng cách cung cấp các different configurations
> - Launch system cũng chịu trách nhiệm giám sát launched processes và report/react to changes in state of those processes

- Có thể sử dụng Python, XML, YAML để viết launch file và sử dụng bằng cmd `ros2 launch`