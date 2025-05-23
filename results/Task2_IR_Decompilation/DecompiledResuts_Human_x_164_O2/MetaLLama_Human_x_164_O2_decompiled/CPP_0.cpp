#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int has_close_elements(std_vector* v, float threshold) {
    float* start = v->_M_base._M_impl._M_start;
    float* finish = v->_M_base._M_impl._M_finish;
    int len = (int)((finish - start) / sizeof(float));
    if (len == 0) return 0;

    int i = 0;
    int j = 1;
    while (j < len) {
        float a = start[i];
        float b = start[j];
        float diff = fabsf(a - b);
        if (diff < threshold) return 1;
        i++;
        j++;
    }
    return 0;
}
