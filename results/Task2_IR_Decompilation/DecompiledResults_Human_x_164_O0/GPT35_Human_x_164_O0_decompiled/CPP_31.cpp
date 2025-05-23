```c
#include <stdbool.h>

bool is_prime(long num) {
    bool result;
    long divisor = 2;
    
    if (num < 2) {
        result = false;
    } else {
        while (divisor * divisor <= num) {
            if (num % divisor == 0) {
                result = false;
                return result;
            }
            divisor++;
        }
        result = true;
    }
    
    return result;
}
```