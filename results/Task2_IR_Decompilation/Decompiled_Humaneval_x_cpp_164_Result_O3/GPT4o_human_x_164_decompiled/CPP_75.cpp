```cpp
#include <iostream>

bool is_multiply_prime(int n) {
    if (n < 4) {
        return n == 2;
    }

    int count = 0;
    int factor = 2;

    while (true) {
        int quotient = n / factor;
        count++;

        if (quotient <= factor) {
            break;
        }

        if (n % factor == 0) {
            if (quotient % factor != 0) {
                return false;
            }
        }

        factor++;
        if (factor * factor > n) {
            break;
        }
    }

    return count == 1;
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