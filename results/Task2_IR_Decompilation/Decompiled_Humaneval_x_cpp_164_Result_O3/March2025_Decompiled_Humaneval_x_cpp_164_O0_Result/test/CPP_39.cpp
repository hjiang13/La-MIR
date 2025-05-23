#include <iostream>
#include <stdexcept>

int prime_fib(int n) {
    int a = 1, b = 2, count = 0;
    while (count < n) {
        int c = a + b;
        a = b;
        b = c;
        bool is_prime = true;
        for (int i = 2; i * i <= a; ++i) {
            if (a % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            ++count;
        }
    }
    return a;
}

int main() {
    try {
        int n;
        std::cin >> n;
        if (n < 0) {
            throw std::runtime_error("Invalid input");
        }
        std::cout << prime_fib(n) << std::endl;
    } catch (...) {
        std::cerr << "An error occurred" << std::endl;
        return 1;
    }
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
