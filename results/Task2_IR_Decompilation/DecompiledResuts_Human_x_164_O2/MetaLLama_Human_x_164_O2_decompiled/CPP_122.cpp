#include <stdio.h>

int add_elements(int* arr, int size) {
    int result = 0;
    if (size > 0) {
        int i;
        for (i = 0; i < size; i++) {
            int val = arr[i] + 99;
            if (val < 199) {
                result += arr[i];
            }
        }
    }
    return result;
}
