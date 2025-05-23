int prime_fib(int n) {
    int a = 1;
    int b = 2;
    int c = 0;
    int i = 0;
    while (i < n) {
        int temp = a + b;
        a = b;
        b = temp;
        if (b < 4 || (b & 1) == 0) {
            i++;
            continue;
        }
        for (int j = 3; j * j <= b; j += 2) {
            if (b % j == 0) {
                goto next;
            }
        }
        i++;
        c = b;
        next:;
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
