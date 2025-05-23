#include <cstdint>

extern "C" int32_t llvm_vector_reduce_mul_v4i32(int32_t arr[4]);

extern "C" int32_t starts_one_endsi(int32_t n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (n > 2) {
        int32_t x = n - 2;
        if (x < 8) {
            return 2;
        } else {
            int32_t mask = x & -8;
            int32_t val = mask | 2;
            int32_t reduced_val = (val - 8) >> 3;
            reduced_val++;
            reduced_val &= 7;

            if (x < 56) {
                int32_t result1[4] = {18, 1, 1, 1};
                int32_t result2[4] = {1, 1, 1, 1};
                int32_t total = x - 8;

                while (total != 0) {
                    result1[0] *= 10;
                    result2[0] *= 10;
                    total--;
                }

                int32_t final_result = llvm_vector_reduce_mul_v4i32(result1) * llvm_vector_reduce_mul_v4i32(result2);
                if (x == mask) {
                    return final_result;
                } else {
                    return 2;
                }
            } else {
                return 0;
            }
        }
    }
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}
