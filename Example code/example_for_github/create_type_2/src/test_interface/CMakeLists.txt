cmake_minimum_required(VERSION 3.8)
project(test_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(create_msgs REQUIRED)

add_executable(talker src/publisher_node.cpp)
ament_target_dependencies(talker rclcpp create_msgs)


install(TARGETS talker DESTINATION lib/${PROJECT_NAME})


ament_package()
