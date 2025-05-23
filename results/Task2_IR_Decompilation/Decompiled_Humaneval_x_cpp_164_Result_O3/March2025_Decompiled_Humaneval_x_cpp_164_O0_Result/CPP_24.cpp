```cpp
#include <iostream>

int largest_divisor(int n) {
    int result;
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
    int n;
    std::cin >> n;
    std::cout << largest_divisor(n) << std::endl;
    return 0;
}
```