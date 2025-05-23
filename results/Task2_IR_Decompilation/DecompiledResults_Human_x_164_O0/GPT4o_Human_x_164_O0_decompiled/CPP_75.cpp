```cpp
#include <stdbool.h>

bool is_multiply_prime(int n) {
    int count = 0;
    int i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
        i++;
    }

    if (n > 1) {
        count++;
    }

    return count == 1;
}
```