- **Translation tool (Công cụ dịch chuyển)**: Để di chuyển object dọc các trục $x, y, z$. Sử dụng bằng cách chọn this tool or press `t` on keyboard and click on object you want to move
	- Chỉ cần click vào object và có thể di chuyển nó trên mặt phẳng $Oxy$. Có thể kiểm soát di chuyển trên mặt nào bằng cách press `x`, `y` or `z`
	- Có thể giữ `Ctrl` để khóa chuyển động theo lưới $1m$
	- Có thể giữ `Shift` để hiện thị 3 trục tọa độ
- **Rotation tool (Công cụ xoay):** Cho phép định hướng model quanh 3 trục. Sử dụng bằng cách chọn this tool or press `r` on keyboard and click on object you want to move
	- Press `x`, `y` or `z`
	- Press `Ctrl`
	- Press `Shift`
- **Scale tool (Công cụ tỷ lệ):** Cho phép thay đổi kích thước model trong 3 trục. Chỉ hoạt động với các simple shapes. Select this tool or press `s` on keyboard
	- Press `x`, `y` or `z`:
	- Press `Ctrl`



## 1. Object population 

- Từ một model ta có thể tạo nhiều clones của nó

```bash
	wget http://github.com/osrf/gazebo_tutorials/raw/master/model_population/files/can_population.world
```

- Run world

```bash
	gazebo ~/can_population.world
```

