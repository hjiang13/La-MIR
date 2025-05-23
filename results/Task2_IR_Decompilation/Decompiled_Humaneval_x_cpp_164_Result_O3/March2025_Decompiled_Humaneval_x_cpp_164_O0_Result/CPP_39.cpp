```cpp
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
```