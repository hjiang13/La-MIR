#include <stdio.h>
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
} std__vector;

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(std__vector* this, int* __position, int* __x) {
    int* __new_start = NULL;
    int __new_size = 0;

    if (this->_M_base._M_impl._M_finish != this->_M_base._M_impl._M_end_of_storage) {
        __new_size = (this->_M_base._M_impl._M_end_of_storage - this->_M_base._M_impl._M_start) << 2;
        if (__new_size == 0) {
            __new_size = 1;
        }
    } else {
        __new_size = (this->_M_base._M_impl._M_end_of_storage - this->_M_base._M_impl._M_start) << 2;
        if (__new_size > 2305843009213693951) {
            __new_size = 2305843009213693951;
        }
    }

    if (__new_size > 0) {
        __new_start = (int*) malloc(__new_size);
        if (!__new_start) {
            _ZSt17__throw_bad_allocv();
        }
    }

    if (this->_M_base._M_impl._M_start != this->_M_base._M_impl._M_finish) {
        memmove(__new_start, this->_M_base._M_impl._M_start, (__position - this->_M_base._M_impl._M_start) * sizeof(int));
    }

    *__position = *__x;

    if (this->_M_base._M_impl._M_finish != __position) {
        memmove(__new_start + (__position - this->_M_base._M_impl._M_start) + 1, __position, (this->_M_base._M_impl._M_finish - __position) * sizeof(int));
    }

    if (this->_M_base._M_impl._M_start != NULL) {
        free(this->_M_base._M_impl._M_start);
    }

    this->_M_base._M_impl._M_start = __new_start;
    this->_M_base._M_impl._M_finish = __new_start + (__position - this->_M_base._M_impl._M_start) + 1;
    this->_M_base._M_impl._M_end_of_storage = __new_start + __new_size;
}

void factorize(std__vector* __result, int __x) {
    int __tmp;
    int __tmp2 = 2;

    while (1) {
        if (__x < 4) {
            if (__result->_M_base._M_impl._M_finish == __result->_M_base._M_impl._M_end_of_storage) {
                _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(__result, __result->_M_base._M_impl._M_finish, &__tmp);
            } else {
                *__result->_M_base._M_impl._M_finish = __x;
                __result->_M_base._M_impl._M_finish++;
            }
            return;
        }

        __tmp = __x;
        __x /= __tmp2;

        if (__x * __tmp2 == __tmp) {
            if (__result->_M_base._M_impl._M_finish == __result->_M_base._M_impl._M_end_of_storage) {
                _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(__result, __result->_M_base._M_impl._M_finish, &__tmp2);
            } else {
                *__result->_M_base._M_impl._M_finish = __tmp2;
                __result->_M_base._M_impl._M_finish++;
            }
        }

        __tmp2++;
    }
}

int main() {
    std__vector __result;
    __result._M_base._M_impl._M_start = NULL;
    __result._M_base._M_impl._M_finish = NULL;
    __result._M_base._M_impl._M_end_of_storage = NULL;

    factorize(&__result, 10);

    return 0;
}
