```cpp
#include <cstdint>

extern "C" int32_t x_or_y(int32_t a, int32_t b, int32_t c) {
    if (a > 1) {
        if (a < 4) {
            return (a & 1) == 0 ? c : b;
        } else {
            int32_t d = 2;
            int8_t e = (a % d) == 0 ? 0 : (a > 1);
            while (true) {
                d++;
                if (d * d > a) {
                    return e == 0 ? c : b;
                }
            }
        }
    }
    return b;
}
```