// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tello_interface:srv/TelloState.idl
// generated code does not contain a copyright notice

#ifndef TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__STRUCT_H_
#define TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/TelloState in the package tello_interface.
typedef struct tello_interface__srv__TelloState_Request
{
  bool request;
} tello_interface__srv__TelloState_Request;

// Struct for a sequence of tello_interface__srv__TelloState_Request.
typedef struct tello_interface__srv__TelloState_Request__Sequence
{
  tello_interface__srv__TelloState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_interface__srv__TelloState_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'state'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/TelloState in the package tello_interface.
typedef struct tello_interface__srv__TelloState_Response
{
  rosidl_runtime_c__String state;
  uint8_t value;
} tello_interface__srv__TelloState_Response;

// Struct for a sequence of tello_interface__srv__TelloState_Response.
typedef struct tello_interface__srv__TelloState_Response__Sequence
{
  tello_interface__srv__TelloState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tello_interface__srv__TelloState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELLO_INTERFACE__SRV__DETAIL__TELLO_STATE__STRUCT_H_
