## 1. Tutorial

### 1.1. Create base class package
- Create `polygon_base` package
```bash
	ros2 pkg create --build-type ament_cmake --dependencies pluginlib --node-name area_node polygon_base
```
- Create header file
- Config `CMakeLists.txt` by adding:
```txt
	# after ament_target_dependencies
	install(
	  DIRECTORY include/
	  DESTINATION include
	)

	# before ament_package
	ament_export_include_directories(
	  include
	)
```
### 1.2. Create plugin package
- Create `polygon_plugins` package
```bash
	ros2 pkg create --build-type ament_cmake --dependencies polygon_base pluginlib --library-name polygon_plugins polygon_plugins
```
- Create plugin source code
- Plugin declaration XML -> CMake plugin declaration
- Back to area_node to use plugin
- Build and run area_node


## Advanced