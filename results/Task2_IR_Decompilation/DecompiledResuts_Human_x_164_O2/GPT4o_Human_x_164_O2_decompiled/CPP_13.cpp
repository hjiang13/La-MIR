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
    int x = 48;
    int y = 18;
    std::cout << "GCD of " << x << " and " << y << " is " << greatest_common_divisor(x, y) << std::endl;
    return 0;
}
```