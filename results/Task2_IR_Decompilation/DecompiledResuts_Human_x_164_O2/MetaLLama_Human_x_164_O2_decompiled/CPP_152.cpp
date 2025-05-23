#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_impl;
} _Vector_base;

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base_int;

typedef struct {
    _Vector_base _M_base;
} vector;

void _Z7compareSt6vectorIiSaIiEES1_(vector* __result, vector* __x, vector* __y) {
    memset(__result, 0, 24);
    int* __x_finish = __x->_M_base._M_impl._M_finish;
    int* __x_start = __x->_M_base._M_impl._M_start;
    int* __y_start = __y->_M_base._M_impl._M_start;
    int* __result_start = __result->_M_base._M_impl._M_start;
    int* __result_finish = __result->_M_base._M_impl._M_finish;
    int* __result_end_of_storage = __result->_M_base._M_impl._M_end_of_storage;

    if (__x_finish == __x_start) {
        return;
    }

    int __n = 0;
    while (1) {
        int __x_value = *__x_start;
        int __y_value = *__y_start;
        int __diff = abs(__x_value - __y_value);
        if (__result_start == __result_finish) {
            int __capacity = __result_end_of_storage - __result_start;
            if (__capacity == 0) {
                __capacity = 1;
            } else {
                __capacity *= 2;
            }
            if (__capacity > 2305843009213693951) {
                __capacity = 2305843009213693951;
            }
            int* __new_start = (int*)malloc(__capacity * 4);
            if (__new_start == NULL) {
                abort();
            }
            __result_start = __new_start;
            __result_finish = __new_start + __capacity;
            __result_end_of_storage = __result_finish;
        }
        *__result_start = __diff;
        __x_start++;
        __y_start++;
        __result_start++;
        __n++;
        if (__x_start == __x_finish) {
            break;
        }
    }
    __result->_M_base._M_impl._M_start = __result_start - __n;
    __result->_M_base._M_impl._M_finish = __result_start;
    __result->_M_base._M_impl._M_end_of_storage = __result_end_of_storage;
}
