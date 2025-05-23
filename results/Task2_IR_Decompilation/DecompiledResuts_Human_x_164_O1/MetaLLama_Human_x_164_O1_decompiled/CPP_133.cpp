#include <stdio.h>
#include <math.h>

int sum_squares(int n, float *arr) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        float val = ceil(arr[i]);
        sum += (int)(val * val);
    }
    return sum;
}
