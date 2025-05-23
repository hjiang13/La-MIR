```cpp
#include <cstdint>

extern "C" int32_t mod(int32_t a, int32_t b) {
    int32_t result = 1;
    int32_t i = 0;

    while (i < a) {
        result = (result * 2) % b;
        i++;
    }

    return result;
}
```