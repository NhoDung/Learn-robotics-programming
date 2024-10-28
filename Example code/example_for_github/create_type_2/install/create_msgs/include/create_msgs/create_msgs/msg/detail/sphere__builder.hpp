// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from create_msgs:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef CREATE_MSGS__MSG__DETAIL__SPHERE__BUILDER_HPP_
#define CREATE_MSGS__MSG__DETAIL__SPHERE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "create_msgs/msg/detail/sphere__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace create_msgs
{

namespace msg
{

namespace builder
{

class Init_Sphere_radius
{
public:
  explicit Init_Sphere_radius(::create_msgs::msg::Sphere & msg)
  : msg_(msg)
  {}
  ::create_msgs::msg::Sphere radius(::create_msgs::msg::Sphere::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::create_msgs::msg::Sphere msg_;
};

class Init_Sphere_center
{
public:
  Init_Sphere_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sphere_radius center(::create_msgs::msg::Sphere::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Sphere_radius(msg_);
  }

private:
  ::create_msgs::msg::Sphere msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::create_msgs::msg::Sphere>()
{
  return create_msgs::msg::builder::Init_Sphere_center();
}

}  // namespace create_msgs

#endif  // CREATE_MSGS__MSG__DETAIL__SPHERE__BUILDER_HPP_
