#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum_squares(float* arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        float val = ceilf(arr[i]);
        result += (int)(val * val);
    }
    return result;
}

int main() {
    // Example usage:
    float arr[] = {1.2f, 2.3f, 3.4f, 4.5f};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = sum_squares(arr, size);
    printf("%d\n", result);
    return 0;
}
