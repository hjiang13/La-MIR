```c
#include <stdlib.h>

typedef struct {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
  _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
  _Vector_base _M_impl;
} vector;

void eati(vector* v, int a, int b, int c) {
  if (c < b) {
    v->_M_impl._M_impl._M_start = (int*)malloc(8);
    v->_M_impl._M_impl._M_finish = v->_M_impl._M_impl._M_start + (a + c);
    v->_M_impl._M_impl._M_end_of_storage = v->_M_impl._M_impl._M_finish;
    *v->_M_impl._M_impl._M_start = a + c;
    v->_M_impl._M_impl._M_start = v->_M_impl._M_impl._M_start + 4;
  } else {
    v->_M_impl._M_impl._M_start = (int*)malloc(8);
    v->_M_impl._M_impl._M_finish = v->_M_impl._M_impl._M_start + (b + a);
    v->_M_impl._M_impl._M_end_of_storage = v->_M_impl._M_impl._M_finish;
    *v->_M_impl._M_impl._M_start = b + a;
    v->_M_impl._M_impl._M_start = v->_M_impl._M_impl._M_start + 4;
  }
  *v->_M_impl._M_impl._M_start = c < b ? 0 : c - b;
}
```