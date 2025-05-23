#include <stdint.h>

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} std_vector;

int below_threshold(std_vector* vec, int threshold) {
    int* start = vec->_M_base._M_impl._M_start;
    int* finish = vec->_M_base._M_impl._M_finish;
    int64_t size = (int64_t)finish - (int64_t)start;
    size >>= 2;

    if (size == 0) {
        return 1;
    }

    int64_t max = (size > 1) ? size : 1;
    int result = 1;
    for (int64_t i = 1; i <= max; i++) {
        if (*(start + i) >= threshold) {
            result = 0;
            break;
        }
    }

    return result;
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
