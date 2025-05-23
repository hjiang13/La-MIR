```c
#include <stdlib.h>

typedef struct {
    int * _M_start;
    int * _M_finish;
    int * _M_end_of_storage;
} _Vector_base;

typedef struct {
    _Vector_base _M_impl;
} vector;

void make_a_pile(vector * v, int n) {
    v->_M_impl._M_start = (int *)malloc(4);
    v->_M_impl._M_finish = v->_M_impl._M_start;
    v->_M_impl._M_end_of_storage = v->_M_impl._M_start + 1;

    *v->_M_impl._M_start = n;
    v->_M_impl._M_finish++;
    v->_M_impl._M_end_of_storage = v->_M_impl._M_finish;

    for (int i = 1; i < n; ++i) {
        int * temp = (int *)malloc(sizeof(int) * (v->_M_impl._M_finish - v->_M_impl._M_start + 1));
        int * temp_finish = temp + (v->_M_impl._M_finish - v->_M_impl._M_start);
        *temp_finish = i + 1;
        for (int j = 0; j < v->_M_impl._M_finish - v->_M_impl._M_start; ++j) {
            temp[j] = v->_M_impl._M_start[j];
        }
        free(v->_M_impl._M_start);
        v->_M_impl._M_start = temp;
        v->_M_impl._M_finish = temp_finish + 1;
        v->_M_impl._M_end_of_storage = v->_M_impl._M_finish;
    }
}