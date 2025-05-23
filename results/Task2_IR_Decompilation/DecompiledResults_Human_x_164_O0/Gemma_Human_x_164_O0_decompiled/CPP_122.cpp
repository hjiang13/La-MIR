Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

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

int add_elements(Vector* vec, int num) {
    int result = 0;
    for (int i = 0; i < num; i++) {
        int val = *(vec->base.impl.impl.data + i);
        if (val >= -99 && val <= 99) {
            result += val;
        }
    }
    return result;
}

int* vector_get(Vector* vec, int index) {
    return vec->base.impl.impl.data + index;
}

int main() {
    // Create a sample vector
    int data[] = {1, 2, 3, 4, 5};
    Vector vec;
    vec.base.impl.impl.data = data;
    vec.base.impl.impl.end = data + 5;
    vec.base.impl.impl.capacity = data + 5;

    int result = add_elements(&vec, 5);
    printf("%d\n", result);

    return 0;
}
```

Please note that this C code is a direct translation of the provided LLVM IR code and might not be the most efficient or idiomatic C code. Additionally, some parts of the IR code, such as the `comdat` and `uwtable` attributes, are not directly translatable to C and have been omitted.