#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} std_vector;

void eat(std_vector* v, int a, int b, int c) {
    if (c < b) {
        v->_M_base._M_impl._M_start = (int*)malloc(8);
        v->_M_base._M_impl._M_finish = v->_M_base._M_impl._M_start + (c + a);
        v->_M_base._M_impl._M_end_of_storage = v->_M_base._M_impl._M_finish;
        *v->_M_base._M_impl._M_start = c + a;
    } else {
        v->_M_base._M_impl._M_start = (int*)malloc(8);
        v->_M_base._M_impl._M_finish = v->_M_base._M_impl._M_start + (b + a);
        v->_M_base._M_impl._M_end_of_storage = v->_M_base._M_impl._M_finish;
        *v->_M_base._M_impl._M_start = b + a;
    }
    memset(v, 0, 24);
}
