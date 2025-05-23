Based on the provided LLVM IR code, here is the equivalent C source code:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector_base {
    float* _M_impl_data;
    float* _M_start;
    float* _M_finish;
    float* _M_end_of_storage;
} Vector_base;

typedef struct Vector {
    Vector_base _M_base;
} Vector;

void get_positive(Vector* __result, Vector* __v) {
    __result->_M_base._M_impl_data = NULL;
    __result->_M_base._M_start = NULL;
    __result->_M_base._M_finish = NULL;
    __result->_M_base._M_end_of_storage = NULL;

    float* __first = __v->_M_base._M_start;
    float* __last = __v->_M_base._M_finish;
    float* __result_start = NULL;
    float* __result_finish = NULL;
    float* __result_end_of_storage = NULL;
    unsigned long __len = 0;

    if (__first == __last) {
        goto __done;
    }

    while (1) {
        float __temp = *__first;
        if (__temp > 0.0f) {
            if (__result_finish == __result_end_of_storage) {
                if (__result_start == NULL) {
                    __result_start = (float*) malloc(sizeof(float));
                    __result_finish = __result_start;
                    __result_end_of_storage = __result_start + 1;
                } else {
                    unsigned long __new_size = (__result_end_of_storage - __result_start) * 2;
                    float* __new_start = (float*) malloc(__new_size * sizeof(float));
                    memcpy(__new_start, __result_start, (__result_finish - __result_start) * sizeof(float));
                    free(__result_start);
                    __result_start = __new_start;
                    __result_finish = __result_start + (__result_end_of_storage - __result_start);
                    __result_end_of_storage = __result_start + __new_size;
                }
            }
            *__result_finish = __temp;
            ++__result_finish;
        }
        ++__first;
        if (__first == __last) {