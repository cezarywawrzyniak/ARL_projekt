// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tello_interface:srv/TelloState.idl
// generated code does not contain a copyright notice

#ifndef TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__BUILDER_HPP_
#define TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__BUILDER_HPP_

#include "tello_interface/srv/detail/tello_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tello_interface
{

namespace srv
{

namespace builder
{

class Init_TelloState_Request_request
{
public:
  Init_TelloState_Request_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tello_interface::srv::TelloState_Request request(::tello_interface::srv::TelloState_Request::_request_type arg)
  {
    msg_.request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_interface::srv::TelloState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_interface::srv::TelloState_Request>()
{
  return tello_interface::srv::builder::Init_TelloState_Request_request();
}

}  // namespace tello_interface


namespace tello_interface
{

namespace srv
{

namespace builder
{

class Init_TelloState_Response_value
{
public:
  explicit Init_TelloState_Response_value(::tello_interface::srv::TelloState_Response & msg)
  : msg_(msg)
  {}
  ::tello_interface::srv::TelloState_Response value(::tello_interface::srv::TelloState_Response::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tello_interface::srv::TelloState_Response msg_;
};

class Init_TelloState_Response_state
{
public:
  Init_TelloState_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TelloState_Response_value state(::tello_interface::srv::TelloState_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_TelloState_Response_value(msg_);
  }

private:
  ::tello_interface::srv::TelloState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tello_interface::srv::TelloState_Response>()
{
  return tello_interface::srv::builder::Init_TelloState_Response_state();
}

}  // namespace tello_interface

#endif  // TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__BUILDER_HPP_
