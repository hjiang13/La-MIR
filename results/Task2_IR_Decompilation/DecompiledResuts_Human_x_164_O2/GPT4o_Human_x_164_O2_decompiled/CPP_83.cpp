```cpp
#include <cstdint>

extern "C" int32_t llvm_vector_reduce_mul_v4i32(int32_t* vec);

int32_t starts_one_endsi(int32_t input) {
    if (input < 1) return 0;
    if (input == 1) return 1;
    if (input > 2) {
        int32_t temp = input - 2;
        if (temp < 8) {
            int32_t aligned = temp & -8;
            int32_t offset = aligned + 2;
            int32_t lshr_val = (aligned - 8) >> 3;
            int32_t val1 = lshr_val + 1;

            if (temp < 56) {
                int32_t vec1[4] = {18, 1, 1, 1};
                int32_t vec2[4] = {1, 1, 1, 1};
                int32_t res = 0;
                do {
                    vec1[0] *= 100000000;
                    vec2[0] *= 100000000;
                    temp -= 8;
                    if (temp == 0) break;
                } while (true);
                int32_t result = 1;
                for (int i = 0; i < 4; ++i) {
                    res += vec1[i] * vec2[i];
                }
                if (temp == aligned) return 0;
                return res;
            } else {
                return 2;
            }
        }
    }
    int32_t result = 0;
    while (true) {
        result += 1;
        if (result == input) break;
    }
    return result;
}
```