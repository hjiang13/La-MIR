```cpp
#include <iostream>

extern "C" int greatest_common_divisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 48; // Example input
    int b = 18; // Example input
    std::cout << "GCD of " << a << " and " << b << " is " << greatest_common_divisor(a, b) << std::endl;
    return 0;
}
```