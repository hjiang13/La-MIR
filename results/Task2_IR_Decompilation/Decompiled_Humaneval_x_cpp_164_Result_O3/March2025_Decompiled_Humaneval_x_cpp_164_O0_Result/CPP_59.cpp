```cpp
#include <iostream>

int largest_prime_factor(int n) {
    int factor = 2;
    while (factor * factor <= n) {
        while (n % factor == 0) {
            n /= factor;
        }
        factor++;
    }
    return n;
}

int main() {
    int number;
    std::cin >> number;
    std::cout << largest_prime_factor(number) << std::endl;
    return 0;
}
```