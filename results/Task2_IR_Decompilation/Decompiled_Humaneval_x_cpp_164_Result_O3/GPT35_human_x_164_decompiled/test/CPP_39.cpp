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
