Based on the provided LLVM IR code, I will generate the equivalent C source code. Please note that this is a direct translation, and the resulting C code may not be optimal or idiomatic.

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
    VectorImpl* impl;
} VectorBase;

typedef struct {
    VectorBase base;
} Vector;

typedef struct {
    Vector* data;
    Vector* end;
    Vector* capacity;
} VectorOfVectorsImplData;

typedef struct {
    VectorOfVectorsImplData impl;
} VectorOfVectorsImpl;

typedef struct {
    VectorOfVectorsImpl* impl;
} VectorOfVectorsBase;

typedef struct {
    VectorOfVectorsBase base;
} VectorOfVectors;

int Vector_size(Vector* vec) {
    return (vec->base.impl.impl.end - vec->base.impl.impl.data) / sizeof(int);
}

Vector* Vector_ix(VectorOfVectors* vec, int index) {
    return vec->base.impl.impl.data + index;
}

int VectorOfVectors_size(VectorOfVectors* vec) {
    return (vec->base.impl.impl.end - vec->base.impl.impl.data) / sizeof(Vector);
}

int Vector_ix_int(Vector* vec, int index) {
    return *(vec->base.impl.impl.data + index);
}

int max_fill(VectorOfVectors* vec, int scalar) {
    int count = 0;
    for (int i = 0; i < VectorOfVectors_size(vec); i++) {
        int sum = 0;
        for (int j = 0; j < Vector_size(Vector_ix(vec, i)); j++) {
            sum += Vector_ix_int(Vector_ix(vec, i), j);
        }
        if (sum > 0) {
            count += (sum - 1) / scalar + 1;
        }
    }
    return count;
}

int main() {
    // Example usage
    VectorOfVectors vec;
    // Initialize vec...
    int result = max_fill(&vec, 5);
    printf("%d\n", result);
    return 0;
}
```

Please note that I've assumed some types and structures based on the IR code, as the original C++ code is not provided. You may need to adjust the types and structures to match your original code. Additionally, I've omitted the implementation of some functions (e.g., `VectorOfVectors_size`) as they are not provided in the IR code.