```cpp
#include <cstdint>

int32_t fizz_buzz(int32_t n) {
    if (n <= 0) return 0;

    int32_t count = 0;
    for (int32_t i = 1; i <= n; ++i) {
        if (i % 11 == 0 || i % 13 == 0) {
            if (i % 10 == 7) count++;
        }
    }
    return count;
}
```