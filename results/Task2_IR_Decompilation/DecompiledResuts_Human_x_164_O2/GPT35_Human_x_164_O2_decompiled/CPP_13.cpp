```c
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
    int num1 = 24;
    int num2 = 36;
    
    int result = greatest_common_divisor(num1, num2);
    
    std::cout << "Greatest Common Divisor of " << num1 << " and " << num2 << " is: " << result << std::endl;
    
    return 0;
}
```