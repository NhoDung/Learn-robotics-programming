- Step 1: Đứng tại root of workspace (bên ngoài `src` folder), thực hiện build workspace:
```bash
	colcon build
```

> [!attention]- Điều gì xảy ra khi build workspace bằng `colcon`
> Tạo thêm các folder cùng mức với `src` folder:
> - `install`
> - `log`
> - `build`

- Các build options của `colcon build`
```bash
	# Allow installed file can be changed by changing files in source space
	colcon build --symlink-install
```

- Step 2: Source current workspace

```bash
	source install/setup.bash
```

> [!question] Tại sao cần source current workspace

