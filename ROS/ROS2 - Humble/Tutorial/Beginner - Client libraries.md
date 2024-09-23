- We will use `colcon` to create and build ROS2 workspace
- `colcon` : Bản cải tiến (iteration) của các ROS build tool như `catkin_make`, `catkin_make_isolated`, `catkin_tool`

> Note: Trong `Tutorials/Beginner: Client libraries/Using colcon to build packages` của ROS2 Humble documentation, không nên build example project vì khi install ROS2 đã install rồi nên khi build lại sẽ gây crash chương trình
# 1 Build workspace
- Trước khi build workspace thì cần resolve dependencies
- Do build types ví dụ như `ament_cmake` không hỗ trợ khái niệm `devel` space và yêu cầu các pkg phải được cài đặt.
- Option `--symlink-install` cho phép các installed files được thay đổi khi các file trong `src` space thay đổi
```bash
	colcon build --symlink-install
```
- Khi build xong thì sẽ tạo ra các folder sau:
```bash
	build install log src
```
- Sau khi đã build xong thì source environments:
```bash
	source install/setup.bash
```
- Colcon hỗ trợ nhiều kiểu build types. 2 kiểu được đề xuất là `ament_cmake` và `ament_python`
# 2 Creating workspace

Các bước gồm có:
- Source ROS2 environment
- Build workspace with colcon
- Source overlay
# 3 Creating package
- Từ trong `src` folder chạy cmd sau:
```bash
	# Với build tool là ament_cmake
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 <package_name> # nếu dùng ament_python thì thay ament_cmake
	# Với build tool là ament_python
	ros2 pkg create --build-type ament_python --license Apache-2.0 <package_name>
```
- Để tạo node thì thêm tham số `--node-name` bằng cách chạy cmd sau:
```bash
	# Với ament_cmake
	ros pkg create --build-type ament_cmake --license Apache-2.0 --node-name <my_node> <my_package>
	# Với ament_python
```
- Để build một package cụ thể:
```bash
	colcon build --packages-select my_package
```
- Tùy vào build tool mà folder structure sẽ khác nhau:
```bash
	# Với ament cmake
	my_package/
		CMakeLists.txt/
		include/my_package/
		package.xml
		src/
	# Với ament_python
	my_package/
		package.xml
		resource/my_package
		setup.cfg
		setup.py
		my_package/ # Không có src folder giống như trên
```
- Có thể có nhiều package trong 1 workspace và có thể từ cả 2 loại build tool

# 4 Example
## 4.1 Example: Create a workspace + Clone a repository + Build
```bash
	# Step 1: Create a workspace

	# Step 2: Create src folder
	mkdir src && cd src
	# Step 3: Clone a repo to src folder
	git clone https://github.com/ros/ros_tutorials.git -b humble
	# Step 4: Back to root of ws and build
	cd ../ && colcon build
	# Step 5: Source underlay and overlay
	source /opt/ros/humble/setup.bash
	source /install/local_setup.bash
```
- Optional: Modify project to check
	- Go to `<path>/src/ros_tutorials/turtlesim/src` and open file `turtle_frame.cpp`
	- Change `setWindowTitle("TurtleSim")` to `setWindowTitle("My_TurtleSim")`
	- Rebuild workspace and source and run `turtlesim_node`
## 4.2 Example: Create a simple package with simple "Hello World" node
```bash
	# Step 1: Create workspace

	# Step 2: Create simple node + package
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 --node-name my_node my_package
	# Step 3: Build and source environment
```

## 4.3 Example: Writing a simple publisher - subscriber by C++
- **Task 1:** Create package name `cpp_pubsub`
```bash
	# Step 1: Create workspace

	# Step 2: Create package
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 cpp_pubsub
```
- **Task 2:** Download code for simple publisher and subscriber to `src` of package
```bash
	# Download publisher source code
	wget -O publisher_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_publisher/member_function.cpp
	# Download subscriber source code
	wget -O subscriber_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_subscriber/member_function.cpp
```
- **Task 3:** Add dependencies to `package.xml`
```xml
	<!--Add information for package-->
	<description>Examples of minimal publisher/subscriber using rclcpp</description>
	<maintainer email="you@email.com">Your Name</maintainer>
	<license>Apache License 2.0</license>

	<!--After ament_cmake buildtool dependencies, patse this code. This dependencies is used by both publisher and subscriber-->
	<depend>rclcpp</depend>
	<depend>std_msgs</depend>
```
- **Task 4:** `CMakeList.txt`
```txt
	# Below existing dependencies find_package(ament_cmake REQUIRED) add following line
	find_package(rclcpp REQUIRED)
	find_package(std_msgs REQUIRED)
	
	# Define executable to run node using "ros2 run"
	# Define executable named talker and path to find code
	add_executable(talker src/publisher_member_function.cpp)
	ament_target_dependencies(talker rclcpp std_msgs)
	# Define executable name listener and path to find code
	add_executable(listener src/subscriber_member_function.cpp)
	ament_target_dependencies(listener rclcpp std_msgs)

	# Add install(TARGETS...) section để 'ros2 run' tìm được executable
	install(TARGETS
	  talker
	  listener
	  DESTINATION lib/${PROJECT_NAME})
```
- **Task 5:** Build package and run workspace
```bash
	# From src of workspace
	colcon build --packages-select cpp_pubsub

	# Terminal 1
	source install/setup.bash
	ros2 run cpp_pubsub  talker

	# Terminal 2
	source install/setup.bash
	ros2 run cpp_pubsub listener
```

### 4.3.1 Fix: Include path for ROS
- Vào `Setting > C_Cpp > Default: Include Path` rồi thêm `/opt/ros/humble/include/**`. Note: Tùy vào ros2 distribution mà thay humble thành distribution khác


### 4.3.2 Examine code
```cpp
	#include <chrono>
	#include <functional>
	#include <memory>
	#include <string>
	
	#include "rclcpp/rclcpp.hpp"
	#include "std_msgs/msg/string.hpp"
	
	using namespace std::chrono_literals;
```
- `rclcpp/rclcpp.hpp` : Cho phép sử dụng hầu hết các phần thông thường của ROS 2 system
- `std_msgs/msg/string.hpp` : Gồm built-in message type dùng để publish data
- Những dòng trên biểu diễn node's dependencies. Gọi lại những dependencies này phải được thêm vào `package.xml` và `CMakeLists.txt`
```cpp
	class MinimalPublisher : public rclcpp::Node
```
- Node class `MinimalPublisher` được inheriting from `rclcpp::Node`. `this` trong code tương ứng với node
```cpp
	public:
	  MinimalPublisher()
	  : Node("minimal_publisher"), count_(0)
	  {
	    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
	    timer_ = this->create_wall_timer(
	    500ms, std::bind(&MinimalPublisher::timer_callback, this));
	  }
```
- Khởi tạo node có tên là `minimal_publisher` với `count_` bằng 0
- Bên trong constructor:
	- Đầu tiên, `publisher_` được khởi tạo với `String` message type với topic tên là `topic` và queue size to limit message là 10
	- Sau đó, `timer_` được khởi tạo và khiến `timer_callback` function được thực thi 2 lần mỗi giây ($500ms$ - 1 lần)
```cpp
	private:
	  void timer_callback()
		  {
		    auto message = std_msgs::msg::String();
		    message.data = "Hello, world! " + std::to_string(count_++);
		    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
		    publisher_->publish(message);
		  }
```
- `timer_callback` là nơi message data được set và published
- `RCLCPP_INFO` macro để print published message ra console
- `publish(message)` để publish data to defined topic
```cpp
	rclcpp::TimerBase::SharedPtr timer_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
	size_t count_;
```
- Declaration of `timer_, publisher_, count_`
```cpp
	int main(int argc, char * argv[])
	{
	  rclcpp::init(argc, argv);
	  rclcpp::spin(std::make_shared<MinimalPublisher>());
	  rclcpp::shutdown();
	  return 0;
	}
```
- Hàm `main` là nơi thực thi code
### 4.3.3 Add dependencies
- Open `package.xml`
	- Add `<description>` , `<maintainer>` and `<license>`
	- Add new line after `ament_cmake` buid tool dependencies and patse the following code. Cái này khai báo rằng package cần `rclcpp` và `std_msgs` khi code được built và thực thi
```xml
	<depend>rclcpp</depend>
	<depend>std_msgs</depend>
```
### 4.3.4 CMakeLists.txt
- Open `CMakeList.txt`. Below existing dependencies `find_package(ament_cmake REQUIRED)`, add lines:
```txt
	find_package(rclcpp REQUIRED)
	find_package(std_msgs REQUIRED)
```
- Add the executable and name it `talker` -> Để có thể run node using `ros2 run`
```txt
	add_executable(talker src/publisher_member_function.cpp) # Define executable with name is talker and path is ...cpp
	ament_target_dependencies(talker rclcpp std_msgs) # Define các dependencies của executable
```
- Add `install(TARGET...)` section để `ros2 run` có thể find executable
```txt
	install(TARGETS
	  talker
	  listener
	  DESTINATION lib/${PROJECT_NAME})
```

## 4.4 Example: Writing a simple service and client by C++
- **Task 1:** Create package
```bash
	# Create workspace

	# Create package
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 cpp_srvcli --dependencies rclcpp example_interfaces # Tham số dependencies khai báo các gói phụ thuộc để không mất công chỉnh sửa nhiều liên quan package.xml và CMakeList.txt
``` 
> Note: Package `example_interfaces` đã định nghĩa sẵn service file
- **Task 2:** Download code for simple service and client
```cpp
	// Service node
	#include "rclcpp/rclcpp.hpp"
	#include "example_interfaces/srv/add_two_ints.hpp"
	
	#include <memory>
	
	void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
	          std::shared_ptr<example_interfaces::srv::AddTwoInts::Response>      response)
	{
	  response->sum = request->a + request->b;
	  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
	                request->a, request->b);
	  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
	}
	
	int main(int argc, char **argv)
	{
	  rclcpp::init(argc, argv);
	
	  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");
	
	  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
	    node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", &add);
	
	  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");
	
	  rclcpp::spin(node);
	  rclcpp::shutdown();
	}
```

```cpp
	// Client node
	#include "rclcpp/rclcpp.hpp"
	#include "example_interfaces/srv/add_two_ints.hpp"
	
	#include <chrono>
	#include <cstdlib>
	#include <memory>
	
	using namespace std::chrono_literals;
	
	int main(int argc, char **argv)
	{
	  rclcpp::init(argc, argv);
	
	  if (argc != 3) {
	      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y");
	      return 1;
	  }
	
	  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_client");
	  rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client =
	    node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
	
	  auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
	  request->a = atoll(argv[1]);
	  request->b = atoll(argv[2]);
	
	  while (!client->wait_for_service(1s)) {
	    if (!rclcpp::ok()) {
	      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
	      return 0;
	    }
	    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
	  }
	
	  auto result = client->async_send_request(request);
	  // Wait for the result.
	  if (rclcpp::spin_until_future_complete(node, result) ==
	    rclcpp::FutureReturnCode::SUCCESS)
	  {
	    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->sum);
	  } else {
	    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
	  }
	
	  rclcpp::shutdown();
	  return 0;
	}
```
- **Task 3:** Add executable
```txt
	add_executable(server src/add_two_ints_server.cpp)
	ament_target_dependencies(server rclcpp example_interfaces)
	
	add_executable(client src/add_two_ints_client.cpp)
	ament_target_dependencies(client rclcpp example_interfaces)
	
	install(TARGETS
	  server
	  client
	  DESTINATION lib/${PROJECT_NAME})
```
- **Task 4:** Build package and run workspace
```bash
	colcon build --packages-select cpp_srvcli

	# Terminal 1: Run service node
	ros2 run cpp_srvcli server

	# Terminal 2: Run client node with parameters
	ros2 run cpp_srvcli client 2 3
```

## 4.5 Example: Creating custom msg and srv file
- **Task 1:** Create package & Custom `.msg` and `.srv` files
```bash
	ros2 pkg create --build-type ament_cmake --license Apache-2.0 tutorial_interfaces

	# Create folder containing .msg and .srv file
	mkdir msg srv
```
- **Task 2:** Definition `.msg` and `.srv` file
```txt
	# Num.msg file
	int64 num

	# Sphere.msg file
	geometry_msgs/Point center
	float64 radius

	# AddThreeInts.srv file
	int64 a
	int64 b
	int64 c
	---
	int64 sum
```
- Để convert interfaces tự định nghĩa sang ngôn ngữ lập trình như C++ hay Python (Để sử dụng trong những ngôn ngữ này) thì thêm dòng sau vào `CMakeLists.txt`
```txt
	find_package(geometry_msgs REQUIRED)
	find_package(rosidl_default_generators REQUIRED)

	rosidl_generate_interfaces(${PROJECT_NAME}
	  "msg/Num.msg"
	  "msg/Sphere.msg"
	  "srv/AddThreeInts.srv"
	  DEPENDENCIES geometry_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
	)
```
> Note: IDL - Interface Definition Language
- Vì các interface nhờ vào `rosidl_default_generators` để generating to code -> Cần declare 1 build tool dependency trên nó. Add following lines within `<package>` element
```xml
	<depend>geometry_msgs</depend>
	<buildtool_depend>rosidl_default_generators</buildtool_depend>
	<exec_depend>rosidl_default_runtime</exec_depend>
	<member_of_group>rosidl_interface_packages</member_of_group>
```
### 4.5.1 Option 1: Test with no source code
- Build workspace and source environment
- Confirm interface creation worked by using command `ros2 interface show`
```bash
	# Check msgs
	ros2 interface show tutorial_interfaces/msg/Num

	# Check srv
	ros2 interface show tutorial_interfaces/srv/AddThreeInts
```
### 4.5.2 Option 2: Test message with pub/sub


### 4.5.3 Option 3: Test service with srv/cli
## 4.6 Example: Implementing custom interfaces

## 4.7 Example: Using parameter in a class by C++

## 4.8 Example: Creating and using plugins by C++
- `pluginlib` : A C++ library for loading and unloading plugins from within a ROS package
- Plugin: Dynamically loadable classes (Các lớp có thể load tự động) và được load from a runtime library
- Pluginlib có thể open a library chứa exported classes bất kỳ lúc nào mà không cần biết trước về library hay header file chứa class definition
- Plugin rất hữu dụng để mở rộng hoặc thay đổi application behavior mà không cần biết application source code

### 4.8.1 Create base class package
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
### 4.8.2 Create plugin package
- Create `polygon_plugins` package
```bash
	ros2 pkg create --build-type ament_cmake --dependencies polygon_base pluginlib --library-name polygon_plugins polygon_plugins
```
- Create plugin source code
- Plugin declaration XML -> CMake plugin declaration
- Back to area_node to use plugin
- Build and run area_node