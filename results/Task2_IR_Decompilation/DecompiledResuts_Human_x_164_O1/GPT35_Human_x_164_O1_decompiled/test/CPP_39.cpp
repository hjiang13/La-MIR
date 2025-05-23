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
