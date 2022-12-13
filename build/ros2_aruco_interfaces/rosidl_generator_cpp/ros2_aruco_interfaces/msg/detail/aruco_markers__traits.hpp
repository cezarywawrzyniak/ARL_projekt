// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_aruco_interfaces:msg/ArucoMarkers.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS__TRAITS_HPP_
#define ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS__TRAITS_HPP_

#include "ros2_aruco_interfaces/msg/detail/aruco_markers__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_aruco_interfaces::msg::ArucoMarkers>()
{
  return "ros2_aruco_interfaces::msg::ArucoMarkers";
}

template<>
inline const char * name<ros2_aruco_interfaces::msg::ArucoMarkers>()
{
  return "ros2_aruco_interfaces/msg/ArucoMarkers";
}

template<>
struct has_fixed_size<ros2_aruco_interfaces::msg::ArucoMarkers>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_aruco_interfaces::msg::ArucoMarkers>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_aruco_interfaces::msg::ArucoMarkers>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS__TRAITS_HPP_
