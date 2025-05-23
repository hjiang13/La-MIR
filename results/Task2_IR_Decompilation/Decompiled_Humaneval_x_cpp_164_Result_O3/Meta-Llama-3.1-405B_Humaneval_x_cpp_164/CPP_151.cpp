#include <stdio.h>
#include <math.h>

long long double_the_difference(float* vec, long long size) {
    long long res = 0;
    for (long long i = 0; i < size; i++) {
        float num = vec[i];
        float rounded = roundf(num);
        float diff = num - rounded;
        if (diff < 1e-4 && num > 0) {
            int rounded_int = (int)rounded;
            if (rounded_int % 2 == 1) {
                res += rounded_int * rounded_int;
            }
        }
    }
    return res;
}
