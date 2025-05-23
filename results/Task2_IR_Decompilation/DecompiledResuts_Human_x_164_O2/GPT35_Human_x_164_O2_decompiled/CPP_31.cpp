```c
#include <stdbool.h>

bool is_prime(long num) {
    if (num < 2) {
        return false;
    } else if (num < 4) {
        return true;
    } else {
        long divisor = 2;
        while (divisor * divisor <= num) {
            if (num % divisor == 0) {
                return false;
            }
            divisor++;
        }
        return true;
    }
}
```