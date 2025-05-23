#include <stdbool.h>

extern "C" int prime_fibi(int n) {
    int a = 1;
    int b = 2;
    int count = 0;

    while (count < n) {
        for (int i = 2; i * i <= b; i++) {
            if (b % i == 0) {
                break;
            }
            if (i * i > b) {
                count++;
                break;
            }
        }
        if (count < n) {
            a = b;
            b++;
        }
    }
    return a;
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
