#include <vector>
#include <cstdint>

extern "C" int64_t llvm_umax_i64(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

int solutions(std::vector<int> *vec) {
    int32_t *data = vec->data();
    int32_t *end = data + vec->size();
    if (data == end) return 0;

    int64_t count = 0;
    int32_t result = 0;

    for (int32_t *ptr = data; ptr < end; ++ptr) {
        int32_t value = *ptr;
        if (value % 2 == 1) {
            result += value;
        }
        count++;
    }

    return result;
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
