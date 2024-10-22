- Gazebo sử dụng các environment variables để locate files và set up communication giữa server và clients

## 1. List of environment variables

- `GAZEBO_MODEL_PATH` :
- `GAZEBO_RESOURCE_PATH` :
- `GAZEBO_MASTER_URI` :
- `GAZEBO_PLUGIN_PATH` :
- `GAZEBO_MODEL_DATABASE_URI` :
---
- Để set enviroment variables thì chạy cmd sau:

```bash
	source /usr/share/gazebo/setup.sh
	# Để không mất công source mỗi lần mở terminal mới thì thêm cmd to .bashrc
	echo "source /usr/share/gazebo/setup.sh" >> ~/.bashrc
```

- Check environment variables of gazebo:

```bash
	printenv | grep -i gazebo
```

> [!question] Problem: Làm sao để add thêm path to enviroment variables ?

