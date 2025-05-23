#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int* size;
    int* capacity;
} Vector;

void sum_product(Vector* result, Vector* input) {
    int* data = input->data;
    int size = input->size[0];
    int capacity = input->capacity[0];

    int sum = 0;
    int product = 1;

    if (size == 0) {
        result->size[0] = 0;
        result->capacity[0] = 8;
        result->data = (int*)malloc(8 * sizeof(int));
        result->data[0] = product;
        result->data[1] = sum;
        return;
    }

    int loop_bound = size / 4;
    int remainder = size % 4;

    int sum_x4[4] = {0};
    int product_x4[4] = {1};

    for (int i = 0; i < loop_bound; i++) {
        int* data_ptr = data + i * 4;
        int data_x4[4] = {data_ptr[0], data_ptr[1], data_ptr[2], data_ptr[3]};
        sum_x4[0] += data_x4[0];
        sum_x4[1] += data_x4[1];
        sum_x4[2] += data_x4[2];
        sum_x4[3] += data_x4[3];
        product_x4[0] *= data_x4[0];
        product_x4[1] *= data_x4[1];
        product_x4[2] *= data_x4[2];
        product_x4[3] *= data_x4[3];
    }

    int final_sum = sum_x4[0] + sum_x4[1] + sum_x4[2] + sum_x4[3];
    int final_product = product_x4[0] * product_x4[1] * product_x4[2] * product_x4[3];

    if (remainder > 0) {
        int* data_ptr = data + loop_bound * 4;
        for (int i = 0; i < remainder; i++) {
            final_sum += data_ptr[i];
            final_product *= data_ptr[i];
        }
    }

    result->size[0] = 2;
    result->capacity[0] = 8;
    result->data = (int*)malloc(8 * sizeof(int));
    result->data[0] = final_product;
    result->data[1] = final_sum;
}
