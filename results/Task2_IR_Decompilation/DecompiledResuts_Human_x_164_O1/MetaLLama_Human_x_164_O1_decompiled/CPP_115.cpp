#include <stdio.h>
#include <stdint.h>

int max_fill(int** vec, int size, int num) {
    int max_sum = 0;
    int i, j;

    for (i = 0; i < size; i++) {
        int inner_size = (vec[i + 1] - vec[i]) / sizeof(int);
        if (inner_size == 0) {
            continue;
        }

        int sum = 0;
        for (j = 0; j < inner_size; j++) {
            sum += vec[i][j];
        }

        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    int total_sum = 0;
    for (i = 0; i < size; i++) {
        int inner_size = (vec[i + 1] - vec[i]) / sizeof(int);
        if (inner_size == 0) {
            continue;
        }

        int sum = 0;
        for (j = 0; j < inner_size; j++) {
            sum += vec[i][j];
        }

        total_sum += sum / num + 1;
    }

    return total_sum - 1;
}
