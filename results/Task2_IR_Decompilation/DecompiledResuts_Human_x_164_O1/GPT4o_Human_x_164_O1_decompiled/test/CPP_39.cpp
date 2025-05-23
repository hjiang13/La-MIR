#include <iostream>

int prime_fibi(int n) {
    int result = 0;
    for (int i = 1, j = 2; i < n; ++i) {
        int is_prime = 1;
        for (int k = 2; k * k <= j; ++k) {
            if (j % k == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            result = j;
        }
        j++;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << prime_fibi(n) << std::endl;
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
