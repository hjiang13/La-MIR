#include <stdio.h>

typedef struct {
    float* data;
    float* begin;
    float* end;
} VectorImplData;

typedef struct {
    VectorImplData impl;
} VectorBase;

typedef struct {
    VectorBase base;
} Vector;

int monotonic(Vector* vec) {
    float* begin = vec->base.impl.begin;
    float* end = vec->base.impl.end;
    int increasing = 0;
    int decreasing = 0;
    float prev = *begin;

    for (int i = 1; i < (end - begin) / sizeof(float); i++) {
        float current = *(begin + i);
        if (current > prev) {
            increasing = 1;
        } else if (current < prev) {
            decreasing = 1;
        }
        prev = current;
    }

    return increasing + decreasing != 2;
}
