```cpp
#include <cstdint>

extern "C" int32_t x_or_y(int32_t a, int32_t b, int32_t c) {
    if (a > 1) {
        if (a < 4) {
            return (a & 1) == 0 ? c : b;
        } else {
            int32_t d = 2;
            uint8_t e = (a > 1) ? 1 : 0;

            while (true) {
                int32_t remainder = a % d;
                e = (remainder == 0) ? 0 : e;
                d++;

                if (d * d > a) {
                    break;
                }
            }
            return (e == 0) ? c : b;
        }
    }
    return b;
}
```