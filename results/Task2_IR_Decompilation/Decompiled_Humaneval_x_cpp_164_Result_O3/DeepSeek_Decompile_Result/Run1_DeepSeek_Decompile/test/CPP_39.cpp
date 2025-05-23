#include <iostream>

int prime_fibi(int n) {
    int a = 1, b = 2;
    int result = 0;

    while (true) {
        if (b <= n) {
            bool is_prime = true;
            for (int i = 2; i * i <= b; ++i) {
                if (b % i == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                result = b;
            }
        }

        int next = a + b;
        if (next > n) {
            break;
        }
        a = b;
        b = next;
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Largest Fibonacci prime <= " << n << ": " << prime_fibi(n) << std::endl;
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
