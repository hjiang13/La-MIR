```cpp
#include <iostream>

int largest_divisor(int n) {
    if (n < 4) return 1;
    for (int i = 2; ; ++i) {
        if (n % i == 0) return n / i;
        if (i * i > n) break;
    }
    return 1;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Largest divisor: " << largest_divisor(number) << std::endl;
    return 0;
}
```