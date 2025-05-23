```c
#include <stdlib.h>

typedef struct vector std::vector;
typedef struct _Vector_base std::_Vector_base;
typedef struct _Vector_impl std::_Vector_base<int, std::allocator<int>>::_Vector_impl;
typedef struct _Vector_impl_data std::_Vector_base<int, std::allocator<int>>::_Vector_impl_data;

struct _Vector_base {
  struct _Vector_impl _Vector_impl;
};

struct _Vector_impl {
  struct _Vector_impl_data _Vector_impl_data;
};

struct _Vector_impl_data {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
};

void eati(std::vector* ret, int a, int b, int c) {

  if (c < b) {
    ret->_M_start = (int*) malloc(8);
    ret->_M_finish = ret->_M_start;
    ret->_M_end_of_storage = ret->_M_start + (a + c);
    *(ret->_M_start) = a + c;
  } else {
    ret->_M_start = (int*) malloc(8);
    ret->_M_finish = ret->_M_start;
    ret->_M_end_of_storage = ret->_M_start + (b + a);
    *(ret->_M_start) = b + a;
  }
  *(ret->_M_start + 1) = c < b ? 0 : (b - c);
  ret->_M_finish = ret->_M_start + 1;
}