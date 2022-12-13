// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fiducial_vlam_msgs:msg/Observations.idl
// generated code does not contain a copyright notice
#include "fiducial_vlam_msgs/msg/detail/observations__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `camera_info`
#include "sensor_msgs/msg/detail/camera_info__functions.h"
// Member `observations`
#include "fiducial_vlam_msgs/msg/detail/observation__functions.h"

bool
fiducial_vlam_msgs__msg__Observations__init(fiducial_vlam_msgs__msg__Observations * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fiducial_vlam_msgs__msg__Observations__fini(msg);
    return false;
  }
  // camera_info
  if (!sensor_msgs__msg__CameraInfo__init(&msg->camera_info)) {
    fiducial_vlam_msgs__msg__Observations__fini(msg);
    return false;
  }
  // observations
  if (!fiducial_vlam_msgs__msg__Observation__Sequence__init(&msg->observations, 0)) {
    fiducial_vlam_msgs__msg__Observations__fini(msg);
    return false;
  }
  return true;
}

void
fiducial_vlam_msgs__msg__Observations__fini(fiducial_vlam_msgs__msg__Observations * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // camera_info
  sensor_msgs__msg__CameraInfo__fini(&msg->camera_info);
  // observations
  fiducial_vlam_msgs__msg__Observation__Sequence__fini(&msg->observations);
}

bool
fiducial_vlam_msgs__msg__Observations__are_equal(const fiducial_vlam_msgs__msg__Observations * lhs, const fiducial_vlam_msgs__msg__Observations * rhs)
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
  // camera_info
  if (!sensor_msgs__msg__CameraInfo__are_equal(
      &(lhs->camera_info), &(rhs->camera_info)))
  {
    return false;
  }
  // observations
  if (!fiducial_vlam_msgs__msg__Observation__Sequence__are_equal(
      &(lhs->observations), &(rhs->observations)))
  {
    return false;
  }
  return true;
}

bool
fiducial_vlam_msgs__msg__Observations__copy(
  const fiducial_vlam_msgs__msg__Observations * input,
  fiducial_vlam_msgs__msg__Observations * output)
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
  // camera_info
  if (!sensor_msgs__msg__CameraInfo__copy(
      &(input->camera_info), &(output->camera_info)))
  {
    return false;
  }
  // observations
  if (!fiducial_vlam_msgs__msg__Observation__Sequence__copy(
      &(input->observations), &(output->observations)))
  {
    return false;
  }
  return true;
}

fiducial_vlam_msgs__msg__Observations *
fiducial_vlam_msgs__msg__Observations__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Observations * msg = (fiducial_vlam_msgs__msg__Observations *)allocator.allocate(sizeof(fiducial_vlam_msgs__msg__Observations), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fiducial_vlam_msgs__msg__Observations));
  bool success = fiducial_vlam_msgs__msg__Observations__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fiducial_vlam_msgs__msg__Observations__destroy(fiducial_vlam_msgs__msg__Observations * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fiducial_vlam_msgs__msg__Observations__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fiducial_vlam_msgs__msg__Observations__Sequence__init(fiducial_vlam_msgs__msg__Observations__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Observations * data = NULL;

  if (size) {
    data = (fiducial_vlam_msgs__msg__Observations *)allocator.zero_allocate(size, sizeof(fiducial_vlam_msgs__msg__Observations), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fiducial_vlam_msgs__msg__Observations__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fiducial_vlam_msgs__msg__Observations__fini(&data[i - 1]);
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
fiducial_vlam_msgs__msg__Observations__Sequence__fini(fiducial_vlam_msgs__msg__Observations__Sequence * array)
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
      fiducial_vlam_msgs__msg__Observations__fini(&array->data[i]);
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

fiducial_vlam_msgs__msg__Observations__Sequence *
fiducial_vlam_msgs__msg__Observations__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Observations__Sequence * array = (fiducial_vlam_msgs__msg__Observations__Sequence *)allocator.allocate(sizeof(fiducial_vlam_msgs__msg__Observations__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fiducial_vlam_msgs__msg__Observations__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fiducial_vlam_msgs__msg__Observations__Sequence__destroy(fiducial_vlam_msgs__msg__Observations__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fiducial_vlam_msgs__msg__Observations__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fiducial_vlam_msgs__msg__Observations__Sequence__are_equal(const fiducial_vlam_msgs__msg__Observations__Sequence * lhs, const fiducial_vlam_msgs__msg__Observations__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fiducial_vlam_msgs__msg__Observations__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fiducial_vlam_msgs__msg__Observations__Sequence__copy(
  const fiducial_vlam_msgs__msg__Observations__Sequence * input,
  fiducial_vlam_msgs__msg__Observations__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fiducial_vlam_msgs__msg__Observations);
    fiducial_vlam_msgs__msg__Observations * data =
      (fiducial_vlam_msgs__msg__Observations *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fiducial_vlam_msgs__msg__Observations__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fiducial_vlam_msgs__msg__Observations__fini(&data[i]);
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
    if (!fiducial_vlam_msgs__msg__Observations__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
