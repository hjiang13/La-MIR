#include <stdbool.h>

bool is_sorted(int* arr, int len) {
    if (len <= 1) return true;

    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i - 1]) return false;

        if (i > 1 && arr[i] == arr[i - 1] && arr[i] == arr[i - 2]) return false;
    }

    return true;
}
