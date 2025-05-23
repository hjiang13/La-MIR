```c
#include <stdbool.h>

int prime_fib(int n) {
    int a = 1;
    int b = 2;
    int sum = 0;
    
    while (b < n) {
        bool is_prime = true;
        
        for (int i = 2; i < b; i++) {
            if (b % i == 0) {
                is_prime = false;
                break;
            }
        }
        
        if (is_prime) {
            sum += b;
        }
        
        int temp = b;
        b += a;
        a = temp;
    }
    
    return sum;
}
```