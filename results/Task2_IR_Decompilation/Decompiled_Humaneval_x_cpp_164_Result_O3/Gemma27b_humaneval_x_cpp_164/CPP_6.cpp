```c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Vector_base {
  struct _Vector_base_impl_data {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
  } _M_impl;
} Vector_base;

typedef struct _String {
  struct _String_alloc_hider _M_alloc;
  long _M_length;
  char* _M_data;
} String;

void parse_nested_parens(Vector_base* result, String* input) {
  Vector_base tmp;
  memset(&tmp, 0, sizeof(Vector_base));
  String current;

  long input_length = strlen(input->_M_data);
  long i = 0;
  while (i < input_length) {
    if (input->_M_data[i] == '(') {
      current._M_length = 0;
      current._M_data = malloc(1);
      current._M_data[0] = '\0';

      i++;
      while (input->_M_data[i] != ')' && i < input_length) {
        current._M_length++;
        current._M_data = realloc(current._M_data, current._M_length + 1);
        current._M_data[current._M_length - 1] = input->_M_data[i];
        current._M_data[current._M_length] = '\0';

        i++;
      }
      if (input->_M_data[i] == ')') {
        i++;
        tmp._M_impl._M_finish++;
        if (tmp._M_impl._M_finish == tmp._M_impl._M_end_of_storage