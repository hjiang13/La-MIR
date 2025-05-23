```c
#include <stdbool.h>

bool is_prime(long num) {
    if (num < 2) {
        return false;
    }

    for (long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
```