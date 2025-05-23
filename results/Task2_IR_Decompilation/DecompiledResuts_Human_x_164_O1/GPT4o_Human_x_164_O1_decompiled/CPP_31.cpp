```cpp
#include <cstdint>

extern "C" {
    bool is_prime(int64_t n) {
        if (n < 2) return false;
        if (n < 4) return true;

        if (n % 2 == 0) return false;

        for (int64_t i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
```