#include <stdint.h>

struct VectorImplData {
    int32_t* _M_start;
    int32_t* _M_finish;
    int32_t* _M_end_of_storage;
};

struct VectorImpl {
    struct VectorImplData _M_impl;
};

struct VectorBase {
    struct VectorImpl _M_impl;
};

struct Vector {
    struct VectorBase _M_base;
};

int32_t llvm_umax_i64(int64_t a, int64_t b) {
    return a > b ? a : b;
}

int1_t will_it_fly(struct Vector* v, int32_t threshold) {
    struct VectorImplData* impl_data = &v->_M_base._M_impl._M_impl;
    int32_t* start = impl_data->_M_start;
    int32_t* finish = impl_data->_M_finish;
    int64_t size = finish - start;
    int64_t half_size = size / 2;

    if (size == 0) {
        return threshold >= 0;
    }

    int64_t max_loop = llvm_umax_i64(half_size, 1);
    int32_t result = 0;

    for (int64_t i = 0; i < max_loop; i++) {
        int32_t* current = start + i;
        int32_t* opposite = start + (size - i - 1);
        result += *current;
        if (*current != *opposite) {
            return 0;
        }
    }

    return result <= threshold;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
