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
