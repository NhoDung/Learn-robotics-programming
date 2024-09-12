# 1 Building a world

## 1.1 Terminology
- **world:** Collection of robots and objects (such as buildings, table, lights) và các global parameters bao gồm sky, ambient light (ánh sáng xung quanh) và physics properties
- **static:** Những entities được đánh dấu là tĩnh (= phần tử `<static>true</static>` trong SDF) là các vật thể chỉ có collision geometry (hình học va chạm) 
	- Những object không được thiết kế để di chuyển thì phải được đánh dấu là tĩnh để cải thiện hiệu suất (performance enhancement)
- **dynamic:** Những entities được đánh dấu là động (= phần tử `<static>false</static>` trong SDF) là các vật thể có cả inertia (quán tính) và collision geometry

Có 2 cách để thêm object vào gazebo:
- Set of simple shapes trên render window
- Model database ở `Insert` tab bên trái

## 1.2 Position model

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
Có thể delete và save world. Để có thể run lại world thì chạy cmd sau:
```bash
	gazebo my_world.sdf # Nếu không ở trong folder chứ file sdf thì viết path đầy đủ
```


# 2 Modifying a world

## 2.1 Scene properties

## 2.2 Physics properties


# 3 Population of models (Nhóm các models)

