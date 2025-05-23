int prime_fib(int n) {
    int i, j, k, m;
    int a, b, c, d;

    a = 1;
    b = 2;
    c = 0;
    d = 0;

    for (i = 1; i <= n; i++) {
        j = a + b;
        k = j % 4;
        if (k == 0) {
            m = j / 4;
            c = c + m;
        }
        a = b;
        b = j;
    }

    return c;
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
