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
} vector;

void count_up_to(vector* v, int n) {
    int i = 2;
    while (i < n) {
        if (i * i > i) {
            if (v->_M_base._M_impl._M_finish == v->_M_base._M_impl._M_start) {
                _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(v, v->_M_base._M_impl._M_start, &i);
            } else if (v->_M_base._M_impl._M_finish != v->_M_base._M_impl._M_end_of_storage) {
                int j = 0;
                while (v->_M_base._M_impl._M_start + j != v->_M_base._M_impl._M_finish) {
                    if ((v->_M_base._M_impl._M_start + j)->_M_impl._M_start % i == 0) {
                        break;
                    }
                    j++;
                }
                if (j == 0) {
                    if (v->_M_base._M_impl._M_start == v->_M_base._M_impl._M_end_of_storage) {
                        _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(v, v->_M_base._M_impl._M_start, &i);
                    } else {
                        v->_M_base._M_impl._M_start-> _M_impl._M_start = i;
                        v->_M_base._M_impl._M_finish = v->_M_base._M_impl._M_start + 1;
                    }
                }
            }
        }
        i++;
    }
}

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(vector* v, int*, int*) {
    int* _M_start = v->_M_base._M_impl._M_start;
    int* _M_finish = v->_M_base._M_impl._M_finish;
    int* _M_end_of_storage = v->_M_base._M_impl._M_end_of_storage;
    size_t __len = _M_finish - _M_start;
    if (__len == 0) {
        _M_start = (int*)malloc(4);
    } else if (__len > 2305843009213693951) {
        _M_start = (int*)malloc(__len * 4);
    } else {
        _M_start = (int*)realloc(_M_start, __len * 4);
    }
    v->_M_base._M_impl._M_start = _M_start;
    v->_M_base._M_impl._M_finish = _M_start + __len;
    v->_M_base._M_impl._M_end_of_storage = _M_start + __len;
}
