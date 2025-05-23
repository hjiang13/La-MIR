#include <stdio.h>
#include <stdint.h>

float max_element(float* data, int size) {
    float max_val = -10000.0f;

    if (size == 0) {
        return max_val;
    }

    int unroll_factor = (size >> 2) + 1;
    int remainder = size & 3;

    if (unroll_factor < 3) {
        for (int i = 0; i < size; i++) {
            float val = data[i];
            if (max_val < val) {
                max_val = val;
            }
        }
    } else {
        int start = 0;
        int end = unroll_factor * 4;

        for (int i = start; i < end; i += 4) {
            float val1 = data[i];
            float val2 = data[i + 1];
            float val3 = data[i + 2];
            float val4 = data[i + 3];

            max_val = (max_val < val1) ? val1 : max_val;
            max_val = (max_val < val2) ? val2 : max_val;
            max_val = (max_val < val3) ? val3 : max_val;
            max_val = (max_val < val4) ? val4 : max_val;
        }

        for (int i = end; i < size; i++) {
            float val = data[i];
            if (max_val < val) {
                max_val = val;
            }
        }
    }

    return max_val;
}
