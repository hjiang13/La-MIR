#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} std_vector;

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(std_vector* this, int* __position, int* __x) {
    int* __tmp = this->_M_base._M_impl;
    int* __tmp1 = this->_M_base._M_impl;
    int __tmp2 = __tmp - __tmp1;
    if (__tmp2 == 0) {
        __tmp2 = 1;
    }
    int __tmp3 = __tmp2 + (__tmp2 >> 1);
    if (__tmp3 < __tmp2 || __tmp3 > 2305843009213693951) {
        __tmp3 = 2305843009213693951;
    }
    if (__tmp3 == 0) {
        __throw_length_error("vector::_M_realloc_insert");
    }
    if (__tmp3 > 2305843009213693951! / sizeof(int)) {
        __throw_bad_alloc();
    }
    int* __tmp4 = malloc(__tmp3 * sizeof(int));
    int* __tmp5 = __tmp4 + (__position - __tmp1);
    *__tmp5 = *__x;
    if (__position - __tmp1 > 0) {
        memmove(__tmp4, __tmp1, (__position - __tmp1) * sizeof(int));
    }
    if (__tmp - __position > 0) {
        memmove(__tmp5 + 1, __position, (__tmp - __position) * sizeof(int));
    }
    if (__tmp1 != 0) {
        free(__tmp1);
    }
    this->_M_base._M_impl = __tmp4;
    this->_M_base._M_impl + __tmp3 = __tmp4 + __tmp3;
}

void rolling_max(std_vector* __result, const std_vector* __x) {
    int __tmp;
    memset(__result, 0, sizeof(std_vector));
    int* __tmp1 = __x->_M_base._M_impl;
    int* __tmp2 = __x->_M_base._M_impl;
    int* __tmp3 = __result->_M_base._M_impl;
    int __tmp4 = __tmp2 - __tmp1;
    if (__tmp4 == 0) {
        return;
    }
    int __tmp5 = 0;
    int* __tmp6 = __tmp1;
    while (1) {
        int __tmp7 = *__tmp6;
        if (__tmp7 > __tmp) {
            __tmp = __tmp7;
        }
        int* __tmp8 = __result->_M_base._M_impl;
        int* __tmp9 = __result->_M_base._M_impl;
        if (__tmp8 == __tmp9) {
            _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(__result, __tmp8, &__tmp);
        } else {
            *__tmp8 = __tmp;
            __tmp8++;
            __result->_M_base._M_impl = __tmp8;
        }
        __tmp6++;
        __tmp5++;
        if (__tmp5 >= __tmp4) {
            break;
        }
    }
}

void __throw_length_error(const char* __msg) {
    // implement __throw_length_error
}

void __throw_bad_alloc(void) {
    // implement __throw_bad_alloc
}
