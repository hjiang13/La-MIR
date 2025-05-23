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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_fib(1) == 2);
    assert (prime_fib(2) == 3);
    assert (prime_fib(3) == 5);
    assert (prime_fib(4) == 13);
    assert (prime_fib(5) == 89);
    assert (prime_fib(6) == 233);
    assert (prime_fib(7) == 1597);
    assert (prime_fib(8) == 28657);
    assert (prime_fib(9) == 514229);
    assert (prime_fib(10) == 433494437);
}
