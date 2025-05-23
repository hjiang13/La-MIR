#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double_the_difference(float* data, long size) {
    long result = 0;
    for (long i = 0; i < size; i++) {
        float value = data[i];
        float rounded = roundf(value);
        float diff = value - rounded;
        if (diff < 1e-4 && value > 0) {
            int rounded_int = (int)rounded;
            if (rounded_int % 2 == 1) {
                result += rounded_int * rounded_int;
            }
        }
    }
    return result;
}
