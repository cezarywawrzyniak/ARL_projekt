// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fiducial_vlam_msgs:msg/Map.idl
// generated code does not contain a copyright notice
#include "fiducial_vlam_msgs/msg/detail/map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `fixed_flags`
// Member `ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `poses`
#include "geometry_msgs/msg/detail/pose_with_covariance__functions.h"

bool
fiducial_vlam_msgs__msg__Map__init(fiducial_vlam_msgs__msg__Map * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fiducial_vlam_msgs__msg__Map__fini(msg);
    return false;
  }
  // marker_length
  // fixed_flags
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->fixed_flags, 0)) {
    fiducial_vlam_msgs__msg__Map__fini(msg);
    return false;
  }
  // ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->ids, 0)) {
    fiducial_vlam_msgs__msg__Map__fini(msg);
    return false;
  }
  // poses
  if (!geometry_msgs__msg__PoseWithCovariance__Sequence__init(&msg->poses, 0)) {
    fiducial_vlam_msgs__msg__Map__fini(msg);
    return false;
  }
  return true;
}

void
fiducial_vlam_msgs__msg__Map__fini(fiducial_vlam_msgs__msg__Map * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // marker_length
  // fixed_flags
  rosidl_runtime_c__int32__Sequence__fini(&msg->fixed_flags);
  // ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->ids);
  // poses
  geometry_msgs__msg__PoseWithCovariance__Sequence__fini(&msg->poses);
}

bool
fiducial_vlam_msgs__msg__Map__are_equal(const fiducial_vlam_msgs__msg__Map * lhs, const fiducial_vlam_msgs__msg__Map * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // marker_length
  if (lhs->marker_length != rhs->marker_length) {
    return false;
  }
  // fixed_flags
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->fixed_flags), &(rhs->fixed_flags)))
  {
    return false;
  }
  // ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->ids), &(rhs->ids)))
  {
    return false;
  }
  // poses
  if (!geometry_msgs__msg__PoseWithCovariance__Sequence__are_equal(
      &(lhs->poses), &(rhs->poses)))
  {
    return false;
  }
  return true;
}

bool
fiducial_vlam_msgs__msg__Map__copy(
  const fiducial_vlam_msgs__msg__Map * input,
  fiducial_vlam_msgs__msg__Map * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // marker_length
  output->marker_length = input->marker_length;
  // fixed_flags
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->fixed_flags), &(output->fixed_flags)))
  {
    return false;
  }
  // ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->ids), &(output->ids)))
  {
    return false;
  }
  // poses
  if (!geometry_msgs__msg__PoseWithCovariance__Sequence__copy(
      &(input->poses), &(output->poses)))
  {
    return false;
  }
  return true;
}

fiducial_vlam_msgs__msg__Map *
fiducial_vlam_msgs__msg__Map__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Map * msg = (fiducial_vlam_msgs__msg__Map *)allocator.allocate(sizeof(fiducial_vlam_msgs__msg__Map), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fiducial_vlam_msgs__msg__Map));
  bool success = fiducial_vlam_msgs__msg__Map__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fiducial_vlam_msgs__msg__Map__destroy(fiducial_vlam_msgs__msg__Map * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fiducial_vlam_msgs__msg__Map__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fiducial_vlam_msgs__msg__Map__Sequence__init(fiducial_vlam_msgs__msg__Map__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Map * data = NULL;

  if (size) {
    data = (fiducial_vlam_msgs__msg__Map *)allocator.zero_allocate(size, sizeof(fiducial_vlam_msgs__msg__Map), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fiducial_vlam_msgs__msg__Map__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fiducial_vlam_msgs__msg__Map__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fiducial_vlam_msgs__msg__Map__Sequence__fini(fiducial_vlam_msgs__msg__Map__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fiducial_vlam_msgs__msg__Map__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fiducial_vlam_msgs__msg__Map__Sequence *
fiducial_vlam_msgs__msg__Map__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Map__Sequence * array = (fiducial_vlam_msgs__msg__Map__Sequence *)allocator.allocate(sizeof(fiducial_vlam_msgs__msg__Map__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fiducial_vlam_msgs__msg__Map__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fiducial_vlam_msgs__msg__Map__Sequence__destroy(fiducial_vlam_msgs__msg__Map__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fiducial_vlam_msgs__msg__Map__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fiducial_vlam_msgs__msg__Map__Sequence__are_equal(const fiducial_vlam_msgs__msg__Map__Sequence * lhs, const fiducial_vlam_msgs__msg__Map__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fiducial_vlam_msgs__msg__Map__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fiducial_vlam_msgs__msg__Map__Sequence__copy(
  const fiducial_vlam_msgs__msg__Map__Sequence * input,
  fiducial_vlam_msgs__msg__Map__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fiducial_vlam_msgs__msg__Map);
    fiducial_vlam_msgs__msg__Map * data =
      (fiducial_vlam_msgs__msg__Map *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fiducial_vlam_msgs__msg__Map__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fiducial_vlam_msgs__msg__Map__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fiducial_vlam_msgs__msg__Map__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
