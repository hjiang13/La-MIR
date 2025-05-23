#include <stdint.h>

int will_it_fly(int* arr, int n, int threshold) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] != arr[n - i - 1]) {
            break;
        }
        sum += arr[i];
    }
    return sum <= threshold;
}
