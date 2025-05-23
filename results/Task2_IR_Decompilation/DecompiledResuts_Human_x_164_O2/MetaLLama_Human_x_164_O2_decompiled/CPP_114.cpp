#include <stdint.h>

int64_t minSubArraySum(int64_t* arr, int64_t n) {
    int64_t min_sum = arr[0];
    int64_t current_sum = arr[0];

    for (int64_t i = 1; i < n; i++) {
        if (current_sum < 0) {
            current_sum = 0;
        }
        current_sum += arr[i];

        if (current_sum < min_sum) {
            min_sum = current_sum;
        }
    }

    return min_sum;
}

int64_t _Z14minSubArraySumSt6vectorIxSaIxEE(int64_t* arr) {
    int64_t n = (int64_t)((uintptr_t)arr[1] - (uintptr_t)arr[0]) / sizeof(int64_t);
    return minSubArraySum(arr, n);
}
