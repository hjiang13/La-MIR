```c
#include <stdbool.h>

bool is_multiply_prime(int num) {
    if (num < 4) {
        return num == 2;
    } else {
        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
```