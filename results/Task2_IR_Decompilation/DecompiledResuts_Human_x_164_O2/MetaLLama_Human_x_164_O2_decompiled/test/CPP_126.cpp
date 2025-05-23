#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct VectorImplData {
    int* ptr;
    int* end;
    int* end_cap;
} VectorImplData;

typedef struct VectorImpl {
    VectorImplData impl;
} VectorImpl;

typedef struct VectorBase {
    VectorImpl impl;
} VectorBase;

typedef struct Vector {
    VectorBase base;
} Vector;

bool is_sorted(Vector* v) {
    int* data = v->base.impl.impl.ptr;
    int size = (v->base.impl.impl.end - v->base.impl.impl.ptr) / sizeof(int);
    if (size <= 1) {
        return true;
    }
    int prev = *data;
    for (int i = 1; i < size; ++i) {
        int curr = *(data + i);
        if (curr < prev) {
            return false;
        }
        if (i > 1 && curr == prev) {
            int prev_prev = *(data + i - 2);
            if (prev_prev == curr) {
                return false;
            }
        }
        prev = curr;
    }
    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_sorted({5}) == true);
    assert (is_sorted({1, 2, 3, 4, 5}) == true);
    assert (is_sorted({1, 3, 2, 4, 5}) == false);
    assert (is_sorted({1, 2, 3, 4, 5, 6}) == true);
    assert (is_sorted({1, 2, 3, 4, 5, 6, 7}) == true);
    assert (is_sorted({1, 3, 2, 4, 5, 6, 7}) == false);
    assert (is_sorted({}) == true);
    assert (is_sorted({1}) == true);
    assert (is_sorted({3, 2, 1}) == false);
    assert (is_sorted({1, 2, 2, 2, 3, 4}) == false);
    assert (is_sorted({1, 2, 3, 3, 3, 4}) == false);
    assert (is_sorted({1, 2, 2, 3, 3, 4}) == true);
    assert (is_sorted({1, 2, 3, 4}) == true);
}
