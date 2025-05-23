```cpp
#include <stdbool.h>

int prime_fib(int n) {
    int a = 1, b = 2, temp = 0;
    bool flag = true;
    
    while (b < n) {
        if (b % a == 0) {
            temp = a;
            a = a + 1;
            b = temp * temp;
            if (b > n) {
                flag = false;
            }
        } else {
            a = a + 1;
        }
    }
    
    return b;
}
```