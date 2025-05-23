#include <stdio.h>
#include <stdlib.h>
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
} vector;

void get_positive(vector* __result, vector* __v) {
    __result->_M_base._M_impl._M_start = NULL;
    __result->_M_base._M_impl._M_finish = NULL;
    __result->_M_base._M_impl._M_end_of_storage = NULL;

    float* __first = __v->_M_base._M_impl._M_start;
    float* __last = __v->_M_base._M_impl._M_finish;

    if (__first == __last) {
        return;
    }

    float* __result_start = NULL;
    float* __result_finish = NULL;
    float* __result_end_of_storage = NULL;

    while (__first != __last) {
        float __x = *__first;

        if (__x > 0.0f) {
            if (__result_start == __result_finish) {
                _M_realloc_insert(__result, __result_finish, &__x);
            } else {
                *__result_finish = __x;
                ++__result_finish;
            }
        }

        ++__first;
    }
}

void _M_realloc_insert(vector* __v, float* __position, float* __x) {
    float* __old_start = __v->_M_base._M_impl._M_start;
    float* __old_finish = __v->_M_base._M_impl._M_finish;

    size_t __len = __old_finish - __old_start;

    if (__len == 0) {
        __v->_M_base._M_impl._M_start = __x;
        __v->_M_base._M_impl._M_finish = __x + 1;
        __v->_M_base._M_impl._M_end_of_storage = __x + 1;
    } else {
        size_t __new_size = __len + 1;
        float* __new_start = malloc(__new_size * sizeof(float));

        if (__new_start == NULL) {
            // Handle memory allocation error
        }

        memmove(__new_start, __old_start, __position - __old_start);
        *__position = *__x;
        memmove(__position + 1, __position, __old_finish - __position);

        __v->_M_base._M_impl._M_start = __new_start;
        __v->_M_base._M_impl._M_finish = __new_start + __new_size;
        __v->_M_base._M_impl._M_end_of_storage = __new_start + __new_size;
    }
}
