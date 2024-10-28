// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from create_msgs:srv/AddThreeInts.idl
// generated code does not contain a copyright notice

#ifndef CREATE_MSGS__SRV__DETAIL__ADD_THREE_INTS__STRUCT_H_
#define CREATE_MSGS__SRV__DETAIL__ADD_THREE_INTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AddThreeInts in the package create_msgs.
typedef struct create_msgs__srv__AddThreeInts_Request
{
  int64_t a;
  int64_t b;
  int64_t c;
} create_msgs__srv__AddThreeInts_Request;

// Struct for a sequence of create_msgs__srv__AddThreeInts_Request.
typedef struct create_msgs__srv__AddThreeInts_Request__Sequence
{
  create_msgs__srv__AddThreeInts_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} create_msgs__srv__AddThreeInts_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AddThreeInts in the package create_msgs.
typedef struct create_msgs__srv__AddThreeInts_Response
{
  int64_t sum;
} create_msgs__srv__AddThreeInts_Response;

// Struct for a sequence of create_msgs__srv__AddThreeInts_Response.
typedef struct create_msgs__srv__AddThreeInts_Response__Sequence
{
  create_msgs__srv__AddThreeInts_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} create_msgs__srv__AddThreeInts_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CREATE_MSGS__SRV__DETAIL__ADD_THREE_INTS__STRUCT_H_
