```cpp
#include <iostream>

int largest_prime_factor(int num) {
    if (num < 4) {
        return num;
    }

    int div = 2;
    while (true) {
        if (num % div == 0) {
            num /= div;
        } else {
            div++;
        }

        if (num == 1 || div * div > num) {
            return num;
        }
    }
}

int main() {
    int num = 13195; // Input number
    int result = largest_prime_factor(num);
    std::cout << "Largest prime factor of " << num << " is: " << result << std::endl;

    return 0;
}
```