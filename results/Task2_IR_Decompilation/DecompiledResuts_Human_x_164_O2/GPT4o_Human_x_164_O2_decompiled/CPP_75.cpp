```cpp
#include <iostream>

bool is_multiply_prime(int n) {
    if (n < 4) {
        return n == 2;
    }
    
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (is_multiply_prime(num)) {
        std::cout << num << " is a multiply prime number." << std::endl;
    } else {
        std::cout << num << " is not a multiply prime number." << std::endl;
    }

    return 0;
}
```