Based on the provided LLVM IR code, I will generate the equivalent C source code. Here is the result:

```c
#include <stdio.h>
#include <stdbool.h>

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

bool pairs_sum_to_zero(Vector* vec) {
    for (int i = 0; i < vec->base.impl.impl.end - vec->base.impl.impl.data; i++) {
        for (int j = i + 1; j < vec->base.impl.impl.end - vec->base.impl.impl.data; j++) {
            if (*(vec->base.impl.impl.data + i) + *(vec->base.impl.impl.data + j) == 0) {
                return true;
            }
        }
    }
    return false;
}

int vector_size(Vector* vec) {
    return (vec->base.impl.impl.end - vec->base.impl.impl.data) / sizeof(int);
}

int* vector_at(Vector* vec, int index) {
    return vec->base.impl.impl.data + index;
}
```

Please note that I've made some assumptions about the original C++ code that generated this IR, as some information is lost during the compilation process. The generated C code may not be exactly the same as the original C++ code, but it should have the same functionality.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (pairs_sum_to_zero({1, 3, 5, 0}) == false);
    assert (pairs_sum_to_zero({1, 3, -2, 1}) == false);
    assert (pairs_sum_to_zero({1, 2, 3, 7}) == false);
    assert (pairs_sum_to_zero({2, 4, -5, 3, 5, 7}) == true);
    assert (pairs_sum_to_zero({1}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 30}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 31}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 30}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 31}) == false);
}
