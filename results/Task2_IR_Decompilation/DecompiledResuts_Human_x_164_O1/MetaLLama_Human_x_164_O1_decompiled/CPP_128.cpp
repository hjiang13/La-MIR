#include <stdio.h>
#include <stdlib.h>

int prod_signs(int* arr, int len) {
    if (len == 0)
        return 0;

    int signs = 0;
    int sum = 0;
    int x;
    for (int i = 0; i < len; i++) {
        x = abs(arr[i]);
        sum += x;
        if (arr[i] < 0)
            signs = -signs;
        else if (arr[i] != 0)
            signs = 1;
    }
    return signs * sum;
}
