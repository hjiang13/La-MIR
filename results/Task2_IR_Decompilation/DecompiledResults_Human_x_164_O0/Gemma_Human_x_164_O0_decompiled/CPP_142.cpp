Based on the provided LLVM IR code, here is the equivalent C source code:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int* end;
    int* capacity;
} VectorImplData;

typedef struct {
    VectorImplData impl;
} VectorImpl;

typedef struct {
    VectorImpl impl;
} VectorBase;

typedef struct {
    VectorBase base;
} Vector;

int vector_size(Vector* vec) {
    return (vec->base.impl.impl.end - vec->base.impl.impl.data) / 4;
}

int* vector_at(Vector* vec, int index) {
    return vec->base.impl.impl.data + index;
}

int sum_squares(Vector* vec) {
    int sum = 0;
    int i = 0;
    while (i < vector_size(vec)) {
        if (i % 3 == 0) {
            sum += vector_at(vec, i)[0] * vector_at(vec, i)[0];
        } else if (i % 4 == 0) {
            sum += vector_at(vec, i)[0] * vector_at(vec, i)[0] * vector_at(vec, i)[0];
        } else {
            sum += vector_at(vec, i)[0];
        }
        i++;
    }
    return sum;
}
```

Please note that this C source code is a direct translation of the provided LLVM IR code and may not be the most efficient or idiomatic C code. Additionally, the `Vector` struct and its related functions are simplified and may not match the original C++ implementation.