#include <stdio.h>
#include <stdbool.h>

bool will_it_fly(int* arr, int size, int threshold) {
    int start = 0;
    int end = size - 1;
    int sum = 0;
    while (start <= end) {
        if (arr[start] == arr[end]) {
            sum += arr[start];
            start++;
            end--;
        } else {
            break;
        }
    }
    return sum <= threshold;
}
