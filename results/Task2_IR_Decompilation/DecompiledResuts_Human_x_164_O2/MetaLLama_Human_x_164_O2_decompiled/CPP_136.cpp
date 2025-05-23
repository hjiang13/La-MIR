#include <stdlib.h>
#include <string.h>

void largest_smallest_integers(int** result, int* arr, int len) {
    int max = 0;
    int min = 0;
    if (len == 0) {
        *result = (int*)malloc(2 * sizeof(int));
        (*result)[0] = min;
        (*result)[1] = max;
        return;
    }

    max = arr[0];
    min = arr[0];

    for (int i = 1; i < len; i++) {
        if (arr[i] < 0) {
            if (min == 0 || arr[i] > min) {
                min = arr[i];
            }
        } else if (arr[i] != 0) {
            if (max == 0 || arr[i] < max) {
                max = arr[i];
            }
        }
    }

    *result = (int*)malloc(2 * sizeof(int));
    (*result)[0] = min;
    (*result)[1] = max;
}
