#include <stdio.h>
#include <string.h>

typedef struct {
    float* _M_start;
    float* _M_finish;
    float* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} std_vector;

void rescale_to_unit(std_vector* __result, std_vector* __x) {
    float* __first = __x->_M_base._M_impl._M_start;
    float* __last = __x->_M_base._M_impl._M_finish;
    unsigned long __len = __last - __first;

    if (__len == 0) {
        __result->_M_base._M_impl._M_start = __first;
        __result->_M_base._M_impl._M_finish = __last;
        __result->_M_base._M_impl._M_end_of_storage = __x->_M_base._M_impl._M_end_of_storage;
        memset(__x, 0, sizeof(std_vector));
        return;
    }

    float __min = 1e5f;
    float __max = -1e5f;

    for (unsigned long __i = 0; __i < __len; ++__i) {
        float __x_i = __first[__i];
        if (__x_i < __min) __min = __x_i;
        if (__x_i > __max) __max = __x_i;
    }

    float __range = __max - __min;

    if (__len == 0) {
        __result->_M_base._M_impl._M_start = __first;
        __result->_M_base._M_impl._M_finish = __last;
        __result->_M_base._M_impl._M_end_of_storage = __x->_M_base._M_impl._M_end_of_storage;
        memset(__x, 0, sizeof(std_vector));
        return;
    }

    for (unsigned long __i = 0; __i < __len; ++__i) {
        float __x_i = __first[__i];
        __first[__i] = (__x_i - __min) / __range;
    }

    __result->_M_base._M_impl._M_start = __first;
    __result->_M_base._M_impl._M_finish = __last;
    __result->_M_base._M_impl._M_end_of_storage = __x->_M_base._M_impl._M_end_of_storage;
    memset(__x, 0, sizeof(std_vector));
}
