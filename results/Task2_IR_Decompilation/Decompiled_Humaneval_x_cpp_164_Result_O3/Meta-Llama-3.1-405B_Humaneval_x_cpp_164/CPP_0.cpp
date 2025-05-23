#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float* data;
    float* end;
    float* capacity;
} vector_base;

typedef struct {
    vector_base base;
} vector;

int has_close_elements(vector* v, float threshold) {
    float* data = v->base.data;
    float* end = v->base.end;
    size_t size = (end - data) / sizeof(float);
    size_t i, j;

    if (size == 0) return 0;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            float diff = fabsf(data[i] - data[j]);
            if (diff < threshold) return 1;
        }
    }

    return 0;
}
