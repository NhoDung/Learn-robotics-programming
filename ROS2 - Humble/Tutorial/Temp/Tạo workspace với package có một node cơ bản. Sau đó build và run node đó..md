> [!info] Các bước cơ bản bao gồm:
> - Step 1: Tạo workspace & src folder 
> - Step 2: Tạo package + node cơ bản và config
> - Step 3: Build + run node


## 1. Sử dụng `ament_cmake`

- Step 1: Đi tới thư mục muốn tạo workspace và tạo workspace với tên là `ros_basic_ws` và `src` folder:

```bash
	mkdir -p ros_basic_ws/src && cd ros_basic_ws/src
```

> [!warning] Tham số `-p` của `mkdir` dùng để tạo các thư mục lồng nhau

- Step 2: Tạo package + node cơ bản

```bash
	ros2 pkg create --build-type ament_cmake <package_name>
```

> [!warning] Mặc định nếu chỉ tạo package sẽ không có node nào được tạo cùng, để tạo thêm 1 node ta làm như sau:

```bash
	ros2 pkg create --build-type ament_cmake <package_name> --node-name <node_name>
```


> [!question] Trả lời một số câu hỏi sau:
> - Có thể sử dụng cmd để tạo package cùng tên không ?
> - Có thể tạo 2 node cùng lúc khi tạo package không ?
> - Có thể tạo thêm 1 node bằng cmd sau khi đã tạo sẵn pkg không ?
> - [[Điều gì sẽ xảy ra khi sử dụng 2 tham số `--node-name` trong cùng 1 cmd `ros2 pkg create` ?]]

- Step 3: Quay về root of workspace để build workspace

```bash
	cd ../ && colcon build
```

- Step 4: Source overlay và run node (Lưu ý: Phải source overlay mỗi khi mở 1 terminal mới)

```bash
	source install/setup.bash
	
	ros2 run <package_name> <node_name>
```

## 2. Sử dụng `ament_python`

> [!note] TODO: Viết nốt



