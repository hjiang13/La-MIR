#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int* data;
    int* size;
    int* capacity;
} VectorImplData;

typedef struct {
    VectorImplData impl;
} VectorBase;

typedef struct {
    VectorBase base;
} Vector;

bool below_zero(Vector* v) {
    int* begin = v->base.impl.data;
    int* end = v->base.impl.size;
    uint64_t size = (uint64_t)end - (uint64_t)begin;
    size >>= 2;

    if (size == 0) {
        return false;
    }

    uint64_t max = __builtin_umax(size, 1);
    int sum = *begin;

    for (uint64_t i = 1; i < max; i++) {
        int value = *(begin + i);
        sum += value;

        if (sum < 0) {
            return true;
        }
    }

    return size > max;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}