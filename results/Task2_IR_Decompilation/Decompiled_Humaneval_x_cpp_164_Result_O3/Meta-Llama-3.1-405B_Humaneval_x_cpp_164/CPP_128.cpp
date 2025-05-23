#include <stdint.h>

int32_t prod_signs(int32_t* vec, int64_t size) {
    int32_t sum = 0;
    int32_t sign = 1;
    for (int64_t i = 0; i < size; i++) {
        int32_t val = vec[i];
        int32_t abs_val = (val < 0) ? -val : val;
        sum += abs_val;
        if (val < 0) {
            sign = -sign;
        } else if (val == 0) {
            sign = 0;
        }
    }
    return sum * sign;
}
