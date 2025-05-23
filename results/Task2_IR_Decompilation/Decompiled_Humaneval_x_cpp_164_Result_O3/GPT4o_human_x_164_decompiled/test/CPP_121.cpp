#include <vector>
#include <cstdint>
#include <algorithm>

extern "C" int64_t llvm_umax_i64(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

extern "C" int32_t llvm_vector_reduce_add_v4i32(int32_t a[4]) {
    return a[0] + a[1] + a[2] + a[3];
}

int32_t solutions(std::vector<int32_t>& vec) {
    int32_t* data = vec.data();
    int32_t* end = data + vec.size();
    
    if (data == end) return 0;

    int64_t distance = end - data;
    if (distance == 0) return 0;

    int64_t step = (distance > 14) ? (distance + 1) / 4 : 0;

    int32_t sum1[4] = {0, 0, 0, 0};
    int32_t sum2[4] = {0, 0, 0, 0};

    for (int64_t i = 0; i < distance; i += 8) {
        for (int64_t j = 0; j < 4; ++j) {
            if (i + j < distance) {
                sum1[j] += data[i + j] % 2 == 1 ? data[i + j] : 0;
            }
            if (i + j + 4 < distance) {
                sum2[j] += data[i + j + 4] % 2 == 1 ? data[i + j + 4] : 0;
            }
        }
    }

    int32_t total1 = llvm_vector_reduce_add_v4i32(sum1);
    int32_t total2 = llvm_vector_reduce_add_v4i32(sum2);
    
    return total1 + total2;
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
