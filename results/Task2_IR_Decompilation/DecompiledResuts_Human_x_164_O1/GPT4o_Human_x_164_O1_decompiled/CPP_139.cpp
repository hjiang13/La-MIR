```cpp
#include <cstdint>

extern "C" int64_t special_factorial(int32_t n) {
    if (n < 1) {
        return 1;
    } else {
        int32_t m = n + 1;
        int64_t result = 1;
        for (int64_t i = 1; i < m; ++i) {
            result *= i;
        }
        return result;
    }
}
```