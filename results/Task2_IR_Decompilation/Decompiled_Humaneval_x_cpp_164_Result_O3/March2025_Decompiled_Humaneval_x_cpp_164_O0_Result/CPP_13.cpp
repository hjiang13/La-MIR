```cpp
#include <iostream>

int greatest_common_divisor(int a, int b) {
    while (a != 0) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        a = a % b;
    }
    return b;
}

int main() {
    int a = 48; // Example input
    int b = 18; // Example input
    std::cout << "GCD of " << a << " and " << b << " is " << greatest_common_divisor(a, b) << std::endl;
    return 0;
}
```