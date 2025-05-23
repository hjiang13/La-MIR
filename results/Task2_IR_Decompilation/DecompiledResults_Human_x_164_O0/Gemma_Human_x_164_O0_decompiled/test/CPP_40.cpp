Based on the provided LLVM IR code, here is the equivalent C source code:

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

bool triples_sum_to_zero(Vector* v) {
    bool result = false;
    for (int i = 0; i < v->base.impl.impl.end - v->base.impl.impl.data; i++) {
        for (int j = i + 1; j < v->base.impl.impl.end - v->base.impl.impl.data; j++) {
            for (int k = j + 1; k < v->base.impl.impl.end - v->base.impl.impl.data; k++) {
                if (v->base.impl.impl.data[i] + v->base.impl.impl.data[j] + v->base.impl.impl.data[k] == 0) {
                    result = true;
                    goto end;
                }
            }
        }
    }
    end:
    return result;
}

int vector_size(Vector* v) {
    return v->base.impl.impl.end - v->base.impl.impl.data;
}

int* vector_at(Vector* v, int index) {
    return v->base.impl.impl.data + index;
}
```

Note that this C code is a direct translation of the provided LLVM IR code and may not be the most efficient or idiomatic C code. Additionally, the `Vector` struct and its related functions are a simplified representation of the original C++ `std::vector` class, and may not provide all the features and functionality of the original class.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (triples_sum_to_zero({1, 3, 5, 0}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -1}) == false);
    assert (triples_sum_to_zero({1, 3, -2, 1}) == true);
    assert (triples_sum_to_zero({1, 2, 3, 7}) == false);
    assert (triples_sum_to_zero({1, 2, 5, 7}) == false);
    assert (triples_sum_to_zero({2, 4, -5, 3, 9, 7}) == true);
    assert (triples_sum_to_zero({1}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -100}) == false);
    assert (triples_sum_to_zero({100, 3, 5, -100}) == false);
}
