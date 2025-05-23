#include <stdint.h>

struct VectorImplData {
    int* ptr;
    int* ptr2;
    int* ptr3;
};

struct VectorBase {
    struct VectorImplData impl;
};

struct Vector {
    struct VectorBase base;
};

int below_threshold(struct Vector* vec, int threshold) {
    int* ptr = vec->base.impl.ptr;
    int* end = vec->base.impl.ptr2;
    int size = (end - ptr) >> 2;
    if (size == 0) return 1;

    int max = size > 0 ? size : 1;
    int x = *ptr;
    if (x < threshold) {
        for (int i = 1; i < max; i++) {
            x = *(ptr + i);
            if (x >= threshold) break;
        }
        return (size <= max);
    }
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
