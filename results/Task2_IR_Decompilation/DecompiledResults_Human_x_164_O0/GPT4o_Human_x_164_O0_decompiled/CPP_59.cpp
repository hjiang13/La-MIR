```cpp
#include <iostream>

int largest_prime_factor(int n) {
    int factor = 2;
    
    while (factor * factor <= n) {
        if (n % factor == 0) {
            n /= factor;
        } else {
            factor++;
        }
    }
    
    return n;
}

int main() {
    int input = 13195; // Example input
    std::cout << largest_prime_factor(input) << std::endl;
    return 0;
}
```