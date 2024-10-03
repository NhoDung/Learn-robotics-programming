> [!check]- Requirement
> - OS : Ubuntu 22.04 (Jammy Jellyfish)
## 1. Install & Setup ROS

> [!summary] Các bước để install ROS 2
> - Step 1: Set `locale`. Để ROS có thể xử lý ký tự và ngôn ngữ khác nhau một cách chính xác
> - Step 2: Add ROS 2 apt repository to system. Vì ROS2 không có sẵn trong kho lưu trữ chính thức của ubuntu
> - Step 3: Install các ROS 2 packages

---
- Set `locale` : UTF-8 support
```bash
	locale  # check for UTF-8

    sudo apt update && sudo apt install locales
    sudo locale-gen en_US en_US.UTF-8 && sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 && export LANG=en_US.UTF-8

    locale  # verify settings
```
- Add ROS 2 apt repository to your system
```bash
	# enable Ubuntu Universe repository
	sudo apt install software-properties-common && sudo add-apt-repository universe
	# add ROS 2 GPG key with apt
	sudo apt update && sudo apt install curl -y
	sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
	# add repository to sources list
	echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
- Install ROS 2 packages
```bash
	sudo apt update && sudo apt upgrade -y
	# desktop install: ROS, RViz, demos, tutorials
	sudo apt install ros-humble-desktop
	# development tools: compilers and other tools to build ros packages
	sudo apt install ros-dev-tools
```
---

> [!question] Tất cả các package của ROS2 được lưu trong `/opt/ros/humble/`
- Để setup và config env -> Để có thể run ROS cmd thì mỗi khi mở terminal mới đều phải `source setup.bash` như sau:
```bash
	source /opt/ros/humble/setup.bash
```
- Để không mất công phải source liên tục thì có thể thêm `setup.bash` và `.bashrc`
```bash
	echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
```

---
> [!warning]- Kiểm tra `setup.bash` trong `.bashrc`. Nếu không `source` thì khi chạy sẽ báo lỗi "cmd not found"

```bash
	gedit ~/.bashrc
```

## 2. ROS 2 tools

### 2.1. Learning tools

> [!info] TurtleSim là 1 demo để học về ROS2

- Install: (Mặc định đã cài khi install ros-desktop)
```bash
	sudo apt update && sudo apt install ros-humble-turtlesim
```
- [Optional] Check installed:
```bash
	ros2 pkg executables turtlesim
```
### 2.2. Management tools

- `rqt` : GUI tool for ROS2 (rqt_graph, rqt_console, ...)
```bash
	sudo apt update && sudo apt install ~nros-humble-rqt*
```
- `rosdep` : Dependency management utility 
```bash
	sudo apt install python3-rosdep
```

### 2.3. Build tools

- `colcon` : Build tools of ROS 2
```bash
	sudo apt install python3-colcon-common-extensions
```
---
### 2.4. All tools

```bash
	sudo apt install ros-humble-rviz2 ros-humble-turtle-tf2-py ros-humble-tf2-ros ros-humble-tf2-tools ros-humble-turtlesim
```

## 3. Basic demo 

> [!question] Problem 1: Demo publisher & subscriber


> [!summary] After installing ROS2 -> Go next to `Tutorial`

