// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fiducial_vlam_msgs:msg/Observations.idl
// generated code does not contain a copyright notice

#ifndef FIDUCIAL_VLAM_MSGS__MSG__DETAIL__OBSERVATIONS__FUNCTIONS_H_
#define FIDUCIAL_VLAM_MSGS__MSG__DETAIL__OBSERVATIONS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fiducial_vlam_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "fiducial_vlam_msgs/msg/detail/observations__struct.h"

/// Initialize msg/Observations message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fiducial_vlam_msgs__msg__Observations
 * )) before or use
 * fiducial_vlam_msgs__msg__Observations__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
bool
fiducial_vlam_msgs__msg__Observations__init(fiducial_vlam_msgs__msg__Observations * msg);

/// Finalize msg/Observations message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
void
fiducial_vlam_msgs__msg__Observations__fini(fiducial_vlam_msgs__msg__Observations * msg);

/// Create msg/Observations message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fiducial_vlam_msgs__msg__Observations__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
fiducial_vlam_msgs__msg__Observations *
fiducial_vlam_msgs__msg__Observations__create();

/// Destroy msg/Observations message.
/**
 * It calls
 * fiducial_vlam_msgs__msg__Observations__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
void
fiducial_vlam_msgs__msg__Observations__destroy(fiducial_vlam_msgs__msg__Observations * msg);

/// Check for msg/Observations message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
bool
fiducial_vlam_msgs__msg__Observations__are_equal(const fiducial_vlam_msgs__msg__Observations * lhs, const fiducial_vlam_msgs__msg__Observations * rhs);

/// Copy a msg/Observations message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
bool
fiducial_vlam_msgs__msg__Observations__copy(
  const fiducial_vlam_msgs__msg__Observations * input,
  fiducial_vlam_msgs__msg__Observations * output);

/// Initialize array of msg/Observations messages.
/**
 * It allocates the memory for the number of elements and calls
 * fiducial_vlam_msgs__msg__Observations__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
bool
fiducial_vlam_msgs__msg__Observations__Sequence__init(fiducial_vlam_msgs__msg__Observations__Sequence * array, size_t size);

/// Finalize array of msg/Observations messages.
/**
 * It calls
 * fiducial_vlam_msgs__msg__Observations__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
void
fiducial_vlam_msgs__msg__Observations__Sequence__fini(fiducial_vlam_msgs__msg__Observations__Sequence * array);

/// Create array of msg/Observations messages.
/**
 * It allocates the memory for the array and calls
 * fiducial_vlam_msgs__msg__Observations__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
fiducial_vlam_msgs__msg__Observations__Sequence *
fiducial_vlam_msgs__msg__Observations__Sequence__create(size_t size);

/// Destroy array of msg/Observations messages.
/**
 * It calls
 * fiducial_vlam_msgs__msg__Observations__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
void
fiducial_vlam_msgs__msg__Observations__Sequence__destroy(fiducial_vlam_msgs__msg__Observations__Sequence * array);

/// Check for msg/Observations message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
bool
fiducial_vlam_msgs__msg__Observations__Sequence__are_equal(const fiducial_vlam_msgs__msg__Observations__Sequence * lhs, const fiducial_vlam_msgs__msg__Observations__Sequence * rhs);

/// Copy an array of msg/Observations messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fiducial_vlam_msgs
bool
fiducial_vlam_msgs__msg__Observations__Sequence__copy(
  const fiducial_vlam_msgs__msg__Observations__Sequence * input,
  fiducial_vlam_msgs__msg__Observations__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FIDUCIAL_VLAM_MSGS__MSG__DETAIL__OBSERVATIONS__FUNCTIONS_H_
