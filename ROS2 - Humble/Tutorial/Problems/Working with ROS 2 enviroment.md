## 1. Check enviroment variables

```bash
	printenv | grep -i ROS
```

> [!Help]- Giải thích cmd trên ?
> - Cmd `printenv` in ra toàn bộ biến môi trường của current session
> - Toán tử `|` để chuyển toàn bộ output cho cmd ngay sau đó
> - Cmd `grep` tìm kiếm trong văn bản theo string cho trước
> 	- Option `-i` : Tìm kiếm không phân biệt chữ hoa hay chữ thường
> 	- String `ROS` : String dùng để tìm kiếm


## 2. Các enviroment variable of ROS 2

- `ROS_DOMAIN_ID`
- `ROS_LOCAL_HOST_ONLY`

> [!question]- Làm sao để thay đổi enviroment variable ?
> - Sử dụng cmd `export`
> - Ngoài ra `export` còn có thể được dùng để chia sẻ biến giữa các tiến trình

