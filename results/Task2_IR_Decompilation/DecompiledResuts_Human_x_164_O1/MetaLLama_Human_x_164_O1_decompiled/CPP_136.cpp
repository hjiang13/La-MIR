#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct VectorImplData {
    int* start;
    int* end;
    int* capacity;
};

struct VectorBase {
    struct VectorImplData impl;
};

struct Vector {
    struct VectorBase base;
};

void largestSmallestIntegers(struct Vector* result, struct Vector* input) {
    int* start = input->base.impl.start;
    int* end = input->base.impl.end;
    int size = end - start;

    if (size == 0) {
        result->base.impl.start = NULL;
        result->base.impl.end = NULL;
        result->base.impl.capacity = NULL;
        return;
    }

    int capacity = (size + 1) / 2;
    int* data = (int*)malloc(sizeof(int) * capacity * 2);
    int min = 0;
    int max = 0;

    for (int i = 0; i < size; i++) {
        int value = start[i];
        if (value < 0) {
            if (min == 0 || value < min) {
                min = value;
            }
        } else {
            if (max == 0 || value > max) {
                max = value;
            }
        }
    }

    result->base.impl.start = data;
    result->base.impl.end = data + capacity;
    result->base.impl.capacity = data + capacity;
    data[0] = min;
    data[1] = max;
}

int main() {
    struct Vector input;
    struct Vector result;
    // Initialize input vector
    input.base.impl.start = (int*)malloc(sizeof(int) * 10);
    input.base.impl.end = input.base.impl.start + 10;
    input.base.impl.capacity = input.base.impl.start + 10;

    // Assign some values to input vector
    for (int i = 0; i < 10; i++) {
        input.base.impl.start[i] = i;
    }

    largestSmallestIntegers(&result, &input);

    // Print result
    printf("Min: %d\n", result.base.impl.start[0]);
    printf("Max: %d\n", result.base.impl.start[1]);

    return 0;
}
