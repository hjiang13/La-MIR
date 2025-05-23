#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int specialFilter(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 10) {
            char str[16];
            sprintf(str, "%d", arr[i]);
            if (str[strlen(str) - 1] % 2 == 1) {
                count++;
            }
        }
    }
    return count;
}
