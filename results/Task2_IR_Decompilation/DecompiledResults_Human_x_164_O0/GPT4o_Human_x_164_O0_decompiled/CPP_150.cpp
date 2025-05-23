```cpp
#include <cstdint>

extern "C" int x_or_y(int32_t a, int32_t b, int32_t c) {
    int32_t result;
    int32_t count = 2;

    if (a < 2) {
        return 0;
    }

    while (true) {
        if (count * count > a) {
            break;
        }

        if (a % count == 0) {
            return 0;
        }

        count++;
    }

    result = (b ? b : c);
    return result;
}
```