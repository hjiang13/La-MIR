```c
#include <stdbool.h>

bool is_multiply_prime(int x) {
    if (x < 4) {
        return x == 2;
    } else {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
}
```