// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tello_interface:srv/TelloState.idl
// generated code does not contain a copyright notice

#ifndef TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__TRAITS_HPP_
#define TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__TRAITS_HPP_

#include "tello_interface/srv/detail/tello_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tello_interface::srv::TelloState_Request>()
{
  return "tello_interface::srv::TelloState_Request";
}

template<>
inline const char * name<tello_interface::srv::TelloState_Request>()
{
  return "tello_interface/srv/TelloState_Request";
}

template<>
struct has_fixed_size<tello_interface::srv::TelloState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tello_interface::srv::TelloState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tello_interface::srv::TelloState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tello_interface::srv::TelloState_Response>()
{
  return "tello_interface::srv::TelloState_Response";
}

template<>
inline const char * name<tello_interface::srv::TelloState_Response>()
{
  return "tello_interface/srv/TelloState_Response";
}

template<>
struct has_fixed_size<tello_interface::srv::TelloState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tello_interface::srv::TelloState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tello_interface::srv::TelloState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tello_interface::srv::TelloState>()
{
  return "tello_interface::srv::TelloState";
}

template<>
inline const char * name<tello_interface::srv::TelloState>()
{
  return "tello_interface/srv/TelloState";
}

template<>
struct has_fixed_size<tello_interface::srv::TelloState>
  : std::integral_constant<
    bool,
    has_fixed_size<tello_interface::srv::TelloState_Request>::value &&
    has_fixed_size<tello_interface::srv::TelloState_Response>::value
  >
{
};

template<>
struct has_bounded_size<tello_interface::srv::TelloState>
  : std::integral_constant<
    bool,
    has_bounded_size<tello_interface::srv::TelloState_Request>::value &&
    has_bounded_size<tello_interface::srv::TelloState_Response>::value
  >
{
};

template<>
struct is_service<tello_interface::srv::TelloState>
  : std::true_type
{
};

template<>
struct is_service_request<tello_interface::srv::TelloState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tello_interface::srv::TelloState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__TRAITS_HPP_
