#include <stdbool.h>
#include <stdint.h>

bool pairs_sum_to_zero(const int* arr, int size) {
    int i, j;
    bool found = false;

    if (size <= 0) return false;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == 0) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    return found;
}
