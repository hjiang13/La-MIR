```cpp
#include <iostream>

bool is_multiply_prime(int n) {
    int count = 0;
    int factor = 2;

    while (factor * factor <= n) {
        while (n % factor == 0) {
            n /= factor;
            count++;
        }
        factor++;
    }

    return count == 2;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (is_multiply_prime(number)) {
        std::cout << number << " is a multiply prime number." << std::endl;
    } else {
        std::cout << number << " is not a multiply prime number." << std::endl;
    }

    return 0;
}
```