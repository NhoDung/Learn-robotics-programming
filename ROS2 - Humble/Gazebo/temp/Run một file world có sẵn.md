## 1. Tutorial

- Để chạy cả server và client gazebo thì dùng cmd sau:

```bash
	gazebo <world_file_name>
```
- Ví dụ:

```bash
	gazebo worlds/pioneer2dx.world
```

> [!warning] Do phải download model nên có thể sẽ mất khoảng vài phút để chạy

> [!warning] Với `world_file_name` thì sử dụng relative path của current directory hoặc enviroment path hay absoluted path đều được

- Để chạy gazebo với plugin thì dùng cmd sau:

```bash
	gazebo -s <plugin_file_name>
```

> [!warning] Nếu gặp phải lỗi gazebo already running thì có thể kill các tiến trình liên quan gazebo 

```bash
	killall -9 gazebo && killall -9 gzserver && killall -9 gzclient
```

- Sử dụng thêm option `--verbose` sẽ hiển thị thông tin chi tiết hơn khi run gazebo

```bash
	gazebo --verbose worlds/pioneer2dx.world
```









































