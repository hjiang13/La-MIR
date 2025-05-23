#include <stdbool.h>

bool monotonic(float* arr, int len) {
    int increasing = 0;
    int decreasing = 0;

    for (int i = 1; i < len; i++) {
        if (arr[i] > arr[i - 1]) {
            increasing = 1;
        }
        if (arr[i] < arr[i - 1]) {
            decreasing = 1;
        }
    }

    return increasing + decreasing != 2;
}
