```cpp
#include <iostream>

bool is_multiply_prime(int n) {
    if (n < 4) {
        return n == 2;
    }

    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ++count;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ++count;
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