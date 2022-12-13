// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tello_interface:srv/TelloState.idl
// generated code does not contain a copyright notice
#include "tello_interface/srv/detail/tello_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
tello_interface__srv__TelloState_Request__init(tello_interface__srv__TelloState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // request
  return true;
}

void
tello_interface__srv__TelloState_Request__fini(tello_interface__srv__TelloState_Request * msg)
{
  if (!msg) {
    return;
  }
  // request
}

bool
tello_interface__srv__TelloState_Request__are_equal(const tello_interface__srv__TelloState_Request * lhs, const tello_interface__srv__TelloState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // request
  if (lhs->request != rhs->request) {
    return false;
  }
  return true;
}

bool
tello_interface__srv__TelloState_Request__copy(
  const tello_interface__srv__TelloState_Request * input,
  tello_interface__srv__TelloState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // request
  output->request = input->request;
  return true;
}

tello_interface__srv__TelloState_Request *
tello_interface__srv__TelloState_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_interface__srv__TelloState_Request * msg = (tello_interface__srv__TelloState_Request *)allocator.allocate(sizeof(tello_interface__srv__TelloState_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tello_interface__srv__TelloState_Request));
  bool success = tello_interface__srv__TelloState_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tello_interface__srv__TelloState_Request__destroy(tello_interface__srv__TelloState_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tello_interface__srv__TelloState_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tello_interface__srv__TelloState_Request__Sequence__init(tello_interface__srv__TelloState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_interface__srv__TelloState_Request * data = NULL;

  if (size) {
    data = (tello_interface__srv__TelloState_Request *)allocator.zero_allocate(size, sizeof(tello_interface__srv__TelloState_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tello_interface__srv__TelloState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tello_interface__srv__TelloState_Request__fini(&data[i - 1]);
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
tello_interface__srv__TelloState_Request__Sequence__fini(tello_interface__srv__TelloState_Request__Sequence * array)
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
      tello_interface__srv__TelloState_Request__fini(&array->data[i]);
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

tello_interface__srv__TelloState_Request__Sequence *
tello_interface__srv__TelloState_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_interface__srv__TelloState_Request__Sequence * array = (tello_interface__srv__TelloState_Request__Sequence *)allocator.allocate(sizeof(tello_interface__srv__TelloState_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tello_interface__srv__TelloState_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tello_interface__srv__TelloState_Request__Sequence__destroy(tello_interface__srv__TelloState_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tello_interface__srv__TelloState_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tello_interface__srv__TelloState_Request__Sequence__are_equal(const tello_interface__srv__TelloState_Request__Sequence * lhs, const tello_interface__srv__TelloState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tello_interface__srv__TelloState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tello_interface__srv__TelloState_Request__Sequence__copy(
  const tello_interface__srv__TelloState_Request__Sequence * input,
  tello_interface__srv__TelloState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tello_interface__srv__TelloState_Request);
    tello_interface__srv__TelloState_Request * data =
      (tello_interface__srv__TelloState_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tello_interface__srv__TelloState_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tello_interface__srv__TelloState_Request__fini(&data[i]);
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
    if (!tello_interface__srv__TelloState_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `state`
#include "rosidl_runtime_c/string_functions.h"

bool
tello_interface__srv__TelloState_Response__init(tello_interface__srv__TelloState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    tello_interface__srv__TelloState_Response__fini(msg);
    return false;
  }
  // value
  return true;
}

void
tello_interface__srv__TelloState_Response__fini(tello_interface__srv__TelloState_Response * msg)
{
  if (!msg) {
    return;
  }
  // state
  rosidl_runtime_c__String__fini(&msg->state);
  // value
}

bool
tello_interface__srv__TelloState_Response__are_equal(const tello_interface__srv__TelloState_Response * lhs, const tello_interface__srv__TelloState_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
tello_interface__srv__TelloState_Response__copy(
  const tello_interface__srv__TelloState_Response * input,
  tello_interface__srv__TelloState_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  // value
  output->value = input->value;
  return true;
}

tello_interface__srv__TelloState_Response *
tello_interface__srv__TelloState_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_interface__srv__TelloState_Response * msg = (tello_interface__srv__TelloState_Response *)allocator.allocate(sizeof(tello_interface__srv__TelloState_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tello_interface__srv__TelloState_Response));
  bool success = tello_interface__srv__TelloState_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tello_interface__srv__TelloState_Response__destroy(tello_interface__srv__TelloState_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tello_interface__srv__TelloState_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tello_interface__srv__TelloState_Response__Sequence__init(tello_interface__srv__TelloState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_interface__srv__TelloState_Response * data = NULL;

  if (size) {
    data = (tello_interface__srv__TelloState_Response *)allocator.zero_allocate(size, sizeof(tello_interface__srv__TelloState_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tello_interface__srv__TelloState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tello_interface__srv__TelloState_Response__fini(&data[i - 1]);
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
tello_interface__srv__TelloState_Response__Sequence__fini(tello_interface__srv__TelloState_Response__Sequence * array)
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
      tello_interface__srv__TelloState_Response__fini(&array->data[i]);
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

tello_interface__srv__TelloState_Response__Sequence *
tello_interface__srv__TelloState_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tello_interface__srv__TelloState_Response__Sequence * array = (tello_interface__srv__TelloState_Response__Sequence *)allocator.allocate(sizeof(tello_interface__srv__TelloState_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tello_interface__srv__TelloState_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tello_interface__srv__TelloState_Response__Sequence__destroy(tello_interface__srv__TelloState_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tello_interface__srv__TelloState_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tello_interface__srv__TelloState_Response__Sequence__are_equal(const tello_interface__srv__TelloState_Response__Sequence * lhs, const tello_interface__srv__TelloState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tello_interface__srv__TelloState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tello_interface__srv__TelloState_Response__Sequence__copy(
  const tello_interface__srv__TelloState_Response__Sequence * input,
  tello_interface__srv__TelloState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tello_interface__srv__TelloState_Response);
    tello_interface__srv__TelloState_Response * data =
      (tello_interface__srv__TelloState_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tello_interface__srv__TelloState_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tello_interface__srv__TelloState_Response__fini(&data[i]);
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
    if (!tello_interface__srv__TelloState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
