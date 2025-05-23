```cpp
#include <cstdint>

extern "C" int64_t special_factorial(int32_t n) {
    if (n < 1) {
        return 1;
    } else {
        int64_t result = 1;
        for (int32_t i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}
```