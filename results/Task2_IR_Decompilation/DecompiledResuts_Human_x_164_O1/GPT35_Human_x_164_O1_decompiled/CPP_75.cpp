```cpp
#include <iostream>

bool is_multiply_prime(int num) {
    if (num < 4) {
        return (num == 2);
    } else {
        int divisor = 2;
        int count = 0;
        while (divisor * divisor <= num) {
            if (num % divisor == 0) {
                count++;
                if (count > 1) {
                    return false;
                }
                num /= divisor;
            } else {
                divisor++;
            }
        }
        return true;
    }
}

int main() {
    int num = 10;
    std::cout << is_multiply_prime(num) << std::endl;
    return 0;
}
```