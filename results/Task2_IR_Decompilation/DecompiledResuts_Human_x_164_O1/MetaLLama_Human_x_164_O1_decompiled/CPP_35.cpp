#include <stdio.h>

float max_element(float* arr, int len) {
    float max_val = -10000.0f;
    for (int i = 0; i < len; i++) {
        float val = arr[i];
        if (max_val < val) {
            max_val = val;
        }
    }
    return max_val;
}
