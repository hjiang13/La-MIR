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
    int num1, num2;
    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;
    int gcd = greatest_common_divisor(num1, num2);
    std::cout << "Greatest Common Divisor: " << gcd << std::endl;
    return 0;
}
```