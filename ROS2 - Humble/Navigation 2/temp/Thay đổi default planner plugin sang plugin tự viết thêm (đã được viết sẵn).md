## 1. Tutorial

- Planner plugin kế thừa từ base class `nav2_core::GlobalPlanner`. Base class này cung cấp 5 virtual methods để implement planner plugin
- Plugin sau đó được planner server sử dụng để tính toán trajectories
- Các virtual methods bắt buộc phải bị override
- 5 methods gồm: `configure()` `active()` `deactive()` `cleanup()` `createPlan()`
- `createPlan()` được sử dụng chính để import algorithm và trả về một global plan với type là `nav_msgs::msg::Path` 


---

- Step 1: Clone 1 plugin package đã config sẵn
- Step 2: Chuyển đến directory `src/turtlebot3_navigation2/param/waffle.yaml` (Do model đang chọn là waffle) và thay thế:

```yaml
	planner_server:
		ros__parameters:
		plugins: ["GridBased"]
		use_sim_time: True
		GridBased:
		    plugin: "nav2_navfn_planner/NavfnPlanner" # For Foxy and later. In Iron and older versions, "/" was used instead of "::"
		    tolerance: 2.0
			use_astar: false
		    allow_unknown: true
```


```yaml
	planner_server:
		ros__parameters:
			plugins: ["GridBased"]
		    use_sim_time: True
		    GridBased:
			    plugin: "nav2_straightline_planner/StraightLine"
			    interpolation_resolution: 0.1
```

- Step 3: Build và source lại là được

---
- Cách khác:

```bash
	ros2 launch nav2_bringup tb3_simulation_launch.py params_file:=/path/to/your_params_file.yaml
```

## 2. Advanced

