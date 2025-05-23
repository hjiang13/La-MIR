#include <stdio.h>

int sum_squares(int* data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int x = data[i];
        if (i % 3 == 0) {
            sum += x * x;
        } else if (i % 3 == 1) {
            sum += x;
        } else {
            sum += x * x * x;
        }
    }
    return sum;
}
