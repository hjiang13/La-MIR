```cpp
#include <iostream>

int largest_divisor(int n) {
    int result = 0;
    int divisor = 2;

    while (divisor * divisor <= n) {
        if (n % divisor == 0) {
            result = n / divisor;
            return result;
        }
        divisor++;
    }
    
    return 1;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    int divisor = largest_divisor(number);
    std::cout << "Largest divisor of " << number << " is " << divisor << std::endl;
    return 0;
}
```