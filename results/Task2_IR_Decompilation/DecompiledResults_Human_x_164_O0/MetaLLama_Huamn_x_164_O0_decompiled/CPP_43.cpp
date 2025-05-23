Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int* end;
    int* capacity;
} vector;

bool pairs_sum_to_zero(vector* v) {
    int i, j;
    for (i = 0; i < (v->end - v->data) / sizeof(int); i++) {
        for (j = i + 1; j < (v->end - v->data) / sizeof(int); j++) {
            if (*((int*)v->data + i) + *((int*)v->data + j) == 0) {
                return true;
            }
        }
    }
    return false;
}

int vector_size(vector* v) {
    return (v->end - v->data) / sizeof(int);
}

int* vector_at(vector* v, int i) {
    return (int*)v->data + i;
}
```

Please note that I've made some assumptions about the original C++ code, such as the structure of the `vector` class and the types used. The generated C code might not be exactly equivalent to the original C++ code, but it should be close enough based on the provided LLVM IR.