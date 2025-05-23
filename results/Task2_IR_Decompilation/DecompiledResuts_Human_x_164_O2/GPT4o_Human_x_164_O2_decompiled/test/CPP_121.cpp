#include <vector>
#include <cstdint>
#include <iostream>

extern "C" int64_t llvm_umax_i64(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

extern "C" int32_t llvm_vector_reduce_add_v4i32(int32_t a[4]) {
    return a[0] + a[1] + a[2] + a[3];
}

extern "C" int32_t solutions(std::vector<int32_t>* vec) {
    int32_t* data = vec->data();
    int64_t size = vec->size();
    if (size == 0) return 0;

    int64_t count = 0;
    int32_t sum = 0;

    for (int64_t i = 0; i < size; i += 4) {
        int32_t values[4] = {0, 0, 0, 0};
        for (int64_t j = 0; j < 4 && (i + j) < size; j++) {
            values[j] = data[i + j];
        }
        
        for (int k = 0; k < 4; k++) {
            if (values[k] % 2 == 1) {
                sum += values[k];
            }
        }
        count++;
    }

    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solutions({5, 8, 7, 1})    == 12);
    assert (solutions({3, 3, 3, 3, 3}) == 9);
    assert (solutions({30, 13, 24, 321}) == 0);
    assert (solutions({5, 9}) == 5);
    assert (solutions({2, 4, 8}) == 0);
    assert (solutions({30, 13, 23, 32}) == 23);
    assert (solutions({3, 13, 2, 9}) == 3);
}
