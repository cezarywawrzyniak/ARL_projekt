// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fiducial_vlam_msgs:msg/Observation.idl
// generated code does not contain a copyright notice
#include "fiducial_vlam_msgs/msg/detail/observation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
fiducial_vlam_msgs__msg__Observation__init(fiducial_vlam_msgs__msg__Observation * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // x0
  // y0
  // x1
  // y1
  // x2
  // y2
  // x3
  // y3
  return true;
}

void
fiducial_vlam_msgs__msg__Observation__fini(fiducial_vlam_msgs__msg__Observation * msg)
{
  if (!msg) {
    return;
  }
  // id
  // x0
  // y0
  // x1
  // y1
  // x2
  // y2
  // x3
  // y3
}

bool
fiducial_vlam_msgs__msg__Observation__are_equal(const fiducial_vlam_msgs__msg__Observation * lhs, const fiducial_vlam_msgs__msg__Observation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // x0
  if (lhs->x0 != rhs->x0) {
    return false;
  }
  // y0
  if (lhs->y0 != rhs->y0) {
    return false;
  }
  // x1
  if (lhs->x1 != rhs->x1) {
    return false;
  }
  // y1
  if (lhs->y1 != rhs->y1) {
    return false;
  }
  // x2
  if (lhs->x2 != rhs->x2) {
    return false;
  }
  // y2
  if (lhs->y2 != rhs->y2) {
    return false;
  }
  // x3
  if (lhs->x3 != rhs->x3) {
    return false;
  }
  // y3
  if (lhs->y3 != rhs->y3) {
    return false;
  }
  return true;
}

bool
fiducial_vlam_msgs__msg__Observation__copy(
  const fiducial_vlam_msgs__msg__Observation * input,
  fiducial_vlam_msgs__msg__Observation * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // x0
  output->x0 = input->x0;
  // y0
  output->y0 = input->y0;
  // x1
  output->x1 = input->x1;
  // y1
  output->y1 = input->y1;
  // x2
  output->x2 = input->x2;
  // y2
  output->y2 = input->y2;
  // x3
  output->x3 = input->x3;
  // y3
  output->y3 = input->y3;
  return true;
}

fiducial_vlam_msgs__msg__Observation *
fiducial_vlam_msgs__msg__Observation__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Observation * msg = (fiducial_vlam_msgs__msg__Observation *)allocator.allocate(sizeof(fiducial_vlam_msgs__msg__Observation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fiducial_vlam_msgs__msg__Observation));
  bool success = fiducial_vlam_msgs__msg__Observation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fiducial_vlam_msgs__msg__Observation__destroy(fiducial_vlam_msgs__msg__Observation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fiducial_vlam_msgs__msg__Observation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fiducial_vlam_msgs__msg__Observation__Sequence__init(fiducial_vlam_msgs__msg__Observation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Observation * data = NULL;

  if (size) {
    data = (fiducial_vlam_msgs__msg__Observation *)allocator.zero_allocate(size, sizeof(fiducial_vlam_msgs__msg__Observation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fiducial_vlam_msgs__msg__Observation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fiducial_vlam_msgs__msg__Observation__fini(&data[i - 1]);
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
fiducial_vlam_msgs__msg__Observation__Sequence__fini(fiducial_vlam_msgs__msg__Observation__Sequence * array)
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
      fiducial_vlam_msgs__msg__Observation__fini(&array->data[i]);
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

fiducial_vlam_msgs__msg__Observation__Sequence *
fiducial_vlam_msgs__msg__Observation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fiducial_vlam_msgs__msg__Observation__Sequence * array = (fiducial_vlam_msgs__msg__Observation__Sequence *)allocator.allocate(sizeof(fiducial_vlam_msgs__msg__Observation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fiducial_vlam_msgs__msg__Observation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fiducial_vlam_msgs__msg__Observation__Sequence__destroy(fiducial_vlam_msgs__msg__Observation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fiducial_vlam_msgs__msg__Observation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fiducial_vlam_msgs__msg__Observation__Sequence__are_equal(const fiducial_vlam_msgs__msg__Observation__Sequence * lhs, const fiducial_vlam_msgs__msg__Observation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fiducial_vlam_msgs__msg__Observation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fiducial_vlam_msgs__msg__Observation__Sequence__copy(
  const fiducial_vlam_msgs__msg__Observation__Sequence * input,
  fiducial_vlam_msgs__msg__Observation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fiducial_vlam_msgs__msg__Observation);
    fiducial_vlam_msgs__msg__Observation * data =
      (fiducial_vlam_msgs__msg__Observation *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fiducial_vlam_msgs__msg__Observation__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fiducial_vlam_msgs__msg__Observation__fini(&data[i]);
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
    if (!fiducial_vlam_msgs__msg__Observation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
