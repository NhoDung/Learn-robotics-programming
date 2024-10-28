// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from create_msgs:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef CREATE_MSGS__MSG__DETAIL__NUM__BUILDER_HPP_
#define CREATE_MSGS__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "create_msgs/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace create_msgs
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::create_msgs::msg::Num num(::create_msgs::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::create_msgs::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::create_msgs::msg::Num>()
{
  return create_msgs::msg::builder::Init_Num_num();
}

}  // namespace create_msgs

#endif  // CREATE_MSGS__MSG__DETAIL__NUM__BUILDER_HPP_
