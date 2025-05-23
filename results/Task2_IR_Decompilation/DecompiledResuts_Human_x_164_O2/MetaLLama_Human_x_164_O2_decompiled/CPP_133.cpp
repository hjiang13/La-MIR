#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float *data;
    float *size;
    float *capacity;
} vector_data;

typedef struct {
    vector_data impl;
} vector_base;

typedef struct {
    vector_base base;
} vector;

int sum_squares(vector *v) {
    float *data = v->base.impl.data;
    float *end = v->base.impl.size;
    int result = 0;
    int i = 0;
    int len = (end - data) / sizeof(float);

    if (len == 0) {
        return 0;
    }

    if (len < 2) {
        float val = ceilf(data[0]);
        result = (int)(val * val);
        return result;
    }

    len = (len + 1) / 2;
    len = len & (~1);

    int j = 0;
    while (len > 0) {
        float val1 = ceilf(data[j]);
        float val2 = ceilf(data[j + 1]);
        result = (int)((float)result + val1 * val1);
        result = (int)((float)result + val2 * val2);
        j += 2;
        len -= 2;
    }

    if (j < (end - data)) {
        float val = ceilf(data[j]);
        result = (int)((float)result + val * val);
    }

    return result;
}
