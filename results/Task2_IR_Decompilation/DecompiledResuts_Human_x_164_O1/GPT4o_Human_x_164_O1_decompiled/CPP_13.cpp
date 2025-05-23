```cpp
#include <iostream>

int greatest_common_divisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1 = 48; // Example input
    int num2 = 18; // Example input
    std::cout << "GCD: " << greatest_common_divisor(num1, num2) << std::endl;
    return 0;
}
```