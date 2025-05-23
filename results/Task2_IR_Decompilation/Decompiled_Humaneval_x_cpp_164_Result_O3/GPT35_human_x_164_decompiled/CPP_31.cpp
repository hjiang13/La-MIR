```cpp
#include <iostream>

bool is_prime(long long num) {
    if (num < 2) {
        return false;
    }
    if (num < 4) {
        return true;
    }
    
    long long divisor = 2;
    while (divisor * divisor <= num) {
        if (num % divisor == 0) {
            return false;
        }
        divisor++;
    }
    
    return true;
}

int main() {
    long long number = 17; // Input number
    bool result = is_prime(number);
    
    if (result) {
        std::cout << number << " is a prime number." << std::endl;
    } else {
        std::cout << number << " is not a prime number." << std::endl;
    }
    
    return 0;
}
```