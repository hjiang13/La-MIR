#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int* begin;
    int* end;
} Vector;

void sum_product(Vector* result, Vector* input) {
    int sum = 0;
    int product = 1;
    int size = input->end - input->begin;

    if (size == 0) {
        result->begin = (int*)malloc(8);
        result->end = result->begin;
        result->data = result->begin;
        *result->data = 0;
        return;
    }

    int* data = (int*)malloc(size * sizeof(int));
    result->begin = data;
    result->end = data + size;
    result->data = data;

    for (int i = 0; i < size; i++) {
        sum += input->begin[i];
        product *= input->begin[i];
    }

    *result->data = sum;
    *(result->data + 1) = product;
}

int main() {
    // Example usage:
    Vector input;
    input.begin = (int*)malloc(5 * sizeof(int));
    input.end = input.begin + 5;
    input.data = input.begin;

    for (int i = 0; i < 5; i++) {
        input.begin[i] = i + 1;
    }

    Vector result;
    sum_product(&result, &input);

    printf("Sum: %d\n", *result.data);
    printf("Product: %d\n", *(result.data + 1));

    free(input.begin);
    free(result.begin);

    return 0;
}
