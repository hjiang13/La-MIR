```c
#include <stdio.h>

int prime_fib(int n) {
    int a = 1, b = 2, temp;
    int fib = 0;
    
    for(int i = 0; i < n; i++) {
        if(is_prime(fib)) {
            printf("%d ", fib);
        }
        
        temp = a;
        a = b;
        b = temp + b;
        fib = a;
    }
    
    return fib;
}

int is_prime(int num) {
    if(num <= 1) {
        return 0;
    }
    
    for(int i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int n = 10;
    prime_fib(n);
    
    return 0;
}
```