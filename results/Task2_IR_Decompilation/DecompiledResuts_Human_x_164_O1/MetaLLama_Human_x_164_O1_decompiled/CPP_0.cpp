#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fabsf(float x) {
    return (x < 0) ? -x : x;
}

int has_close_elements(float* data, int size, float threshold) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (fabsf(data[i] - data[j]) < threshold) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    // Empty main function
    return 0;
}
