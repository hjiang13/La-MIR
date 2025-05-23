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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (minSubArraySum({2, 3, 4, 1, 2, 4}) == 1);
    assert (minSubArraySum({-1, -2, -3}) == -6);
    assert (minSubArraySum({-1, -2, -3, 2, -10}) == -14);
    assert (minSubArraySum({-9999999999999999}) == -9999999999999999);
    assert (minSubArraySum({0, 10, 20, 1000000}) == 0);
    assert (minSubArraySum({-1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({100, -1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({10, 11, 13, 8, 3, 4}) == 3);
    assert (minSubArraySum({100, -33, 32, -1, 0, -2}) == -33);
    assert (minSubArraySum({-10}) == -10);
    assert (minSubArraySum({7}) == 7);
    assert (minSubArraySum({1, -1}) == -1);
}
