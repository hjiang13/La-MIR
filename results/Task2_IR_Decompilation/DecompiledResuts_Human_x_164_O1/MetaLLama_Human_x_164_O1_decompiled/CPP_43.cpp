#include <stdio.h>

int pairs_sum_to_zero(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == 0) {
                return 1;
            }
        }
    }
    return 0;
}
