#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float mean_absolute_deviation(float *vector, int length) {
    if (length == 0) {
        return 0.0f;
    }

    float sum = 0.0f;
    for (int i = 0; i < length; i++) {
        sum += vector[i];
    }

    float mean = sum / length;

    float sum_abs_diff = 0.0f;
    for (int i = 0; i < length; i++) {
        sum_abs_diff += fabs(vector[i] - mean);
    }

    return sum_abs_diff / length;
}
