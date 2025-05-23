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
