```cpp
#include <cstdint>

int64_t special_factorial(int32_t n) {
    int32_t i = 1;
    int64_t result = 1;
    int64_t temp = 1;

    while (i <= n) {
        result *= i;
        temp *= result;
        ++i;
    }

    return temp;
}
```