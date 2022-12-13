// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tello_interface:srv/TelloState.idl
// generated code does not contain a copyright notice

#ifndef TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__STRUCT_HPP_
#define TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tello_interface__srv__TelloState_Request __attribute__((deprecated))
#else
# define DEPRECATED__tello_interface__srv__TelloState_Request __declspec(deprecated)
#endif

namespace tello_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TelloState_Request_
{
  using Type = TelloState_Request_<ContainerAllocator>;

  explicit TelloState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request = false;
    }
  }

  explicit TelloState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request = false;
    }
  }

  // field types and members
  using _request_type =
    bool;
  _request_type request;

  // setters for named parameter idiom
  Type & set__request(
    const bool & _arg)
  {
    this->request = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tello_interface::srv::TelloState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tello_interface::srv::TelloState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tello_interface::srv::TelloState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tello_interface::srv::TelloState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tello_interface__srv__TelloState_Request
    std::shared_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tello_interface__srv__TelloState_Request
    std::shared_ptr<tello_interface::srv::TelloState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TelloState_Request_ & other) const
  {
    if (this->request != other.request) {
      return false;
    }
    return true;
  }
  bool operator!=(const TelloState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TelloState_Request_

// alias to use template instance with default allocator
using TelloState_Request =
  tello_interface::srv::TelloState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tello_interface


#ifndef _WIN32
# define DEPRECATED__tello_interface__srv__TelloState_Response __attribute__((deprecated))
#else
# define DEPRECATED__tello_interface__srv__TelloState_Response __declspec(deprecated)
#endif

namespace tello_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TelloState_Response_
{
  using Type = TelloState_Response_<ContainerAllocator>;

  explicit TelloState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = "";
      this->value = 0;
    }
  }

  explicit TelloState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = "";
      this->value = 0;
    }
  }

  // field types and members
  using _state_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _state_type state;
  using _value_type =
    uint8_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__state(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__value(
    const uint8_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tello_interface::srv::TelloState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tello_interface::srv::TelloState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tello_interface::srv::TelloState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tello_interface::srv::TelloState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tello_interface__srv__TelloState_Response
    std::shared_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tello_interface__srv__TelloState_Response
    std::shared_ptr<tello_interface::srv::TelloState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TelloState_Response_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const TelloState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TelloState_Response_

// alias to use template instance with default allocator
using TelloState_Response =
  tello_interface::srv::TelloState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tello_interface

namespace tello_interface
{

namespace srv
{

struct TelloState
{
  using Request = tello_interface::srv::TelloState_Request;
  using Response = tello_interface::srv::TelloState_Response;
};

}  // namespace srv

}  // namespace tello_interface

#endif  // TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__STRUCT_HPP_
