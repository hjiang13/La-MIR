```c
#include <stdio.h>

int prime_fib(int n) {
    int a = 1, b = 2, next = 0, sum = 0;
    
    while (a < n) {
        if (b % 2 == 0) {
            sum += b;
        }
        
        next = a + b;
        a = b;
        b = next;
    }
    
    return sum;
}

int main() {
    int n = 10;
    int result = prime_fib(n);
    
    printf("Sum of even Fibonacci numbers less than %d is: %d\n", n, result);
    
    return 0;
}
```