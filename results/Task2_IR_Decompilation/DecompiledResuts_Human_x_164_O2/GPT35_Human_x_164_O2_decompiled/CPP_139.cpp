```cpp
#include <iostream>

int special_factorial(int num) {
    if (num < 1) {
        return 1;
    } else {
        int result = 1;
        for (int i = 1; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}

int main() {
    int input = 5;
    int output = special_factorial(input);
    std::cout << "Factorial of " << input << " is: " << output << std::endl;
    return 0;
}
```