
> [!important] Các bước cần có để viết `package.xml` : 
> - Step 1: (Không bắt buộc) Khai báo các thông tin cơ bản của package như: Name, version, license, ...
> - Step 2: Khai báo build tool được sử dụng
> - Step 3: Khai báo các dependencies (nếu có) ngay sau khi khai báo build tool
> - Step 4: (Không bắt buộc) Khai báo các test dependencies
> - Step 5: Xuất thông tin của build tool


## 1. C++

- Đoạn code bắt buộc phải có trong `package.xml` :
```XML
	<buildtool_depend>ament_cmake</buildtool_depend>

	<depend>rclcpp</depend>
	<depend>std_msgs</depend>
	
	<export>
		<build_type>ament_cmake</build_type>
	</export>
```


## 2. Python

- Đoạn code bắt buộc phải có trong `package.xml` :

```XML
	<exec_depend>rclpy</exec_depend>
	<exec_depend>std_msgs</exec_depend>
```


> [!question] Tại sao phải dùng <exec_depend> với python package còn với cpp package thì không ?
> Do Python là interpreter language còn Cpp là compiler language

