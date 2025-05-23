```c
#include <stdlib.h>
#include <string.h>

typedef struct {
    int * _M_start;
    int * _M_finish;
    int * _M_end_of_storage;
} _Vector_base;

typedef struct {
    _Vector_base _M_impl;
} vector;

void sort_array(vector * dest, vector * src) {
    int * begin = src->_M_impl._M_start;
    int * end = src->_M_impl._M_finish;
    if (begin == end) {
        return;
    }
    int * iter = begin;
    int * last = end;
    while (iter != last) {
        int val = *iter;
        if (val == 0) {
            iter++;
        } else {
            last--;
            int tmp = *last;
            *last = val;
            *iter = tmp;
        }
    }
    int * p = dest->_M_impl._M_start;
    int * q = dest->_M_impl._M_finish;
    int * r = begin;

    while (p != q && r != end) {
        *p++ = *r++;
    }

    free(dest->_M_impl._M_start);
    dest->_M_impl._M_start = (int *)malloc(sizeof(int) * (end - begin));
    dest->_M_impl._M_finish = dest->_M_impl._M_start + (end - begin);
    dest->_M_impl._M_end_of_storage = dest->_M_impl._M_finish;

    memcpy(dest->_M_impl._M_start, begin, sizeof(int) * (end - begin));

    
    int i = 0;
    while (i < dest->_M_impl._M_finish - dest->_M_impl._M_start) {
        int j = i + 1;
        while (j < dest->_M_impl._M_finish - dest->_M_impl._M_start) {
            if (dest->_M_impl._M_start[i] > dest->_M_impl._M_start[j]) {
                int tmp = dest->_M_impl._M_start[i];
                dest->_M_impl._M_start[i] = dest->_M_impl._M_start[j];
                dest->_M_impl._M_start[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

```