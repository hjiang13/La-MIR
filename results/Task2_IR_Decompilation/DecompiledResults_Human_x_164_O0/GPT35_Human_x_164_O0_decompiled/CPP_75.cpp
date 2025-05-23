```c
#include <stdbool.h>

bool is_multiply_prime(int num) {
    int divisor = 2;
    
    while (divisor * divisor <= num) {
        if (num % divisor == 0) {
            return false;
        } else {
            divisor++;
        }
    }
    
    return true;
}
```