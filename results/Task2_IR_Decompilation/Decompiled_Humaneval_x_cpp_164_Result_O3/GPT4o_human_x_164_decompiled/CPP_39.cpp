```cpp
#include <iostream>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int prime_fibi(int n) {
    int count = 0;
    int last_prime = 0;
    for (int i = 1; count < n; i++) {
        if (is_prime(i)) {
            last_prime = i;
            count++;
        }
    }
    return last_prime;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "The " << n << "th prime number is: " << prime_fibi(n) << std::endl;
    return 0;
}
```