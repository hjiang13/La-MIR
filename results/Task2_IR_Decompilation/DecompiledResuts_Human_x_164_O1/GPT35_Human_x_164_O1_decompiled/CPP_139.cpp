```cpp
#include <iostream>

long long special_factorial(int num) {
    if (num < 1) {
        return 1;
    }
    
    int new_num = num + 1;
    long long result = 1;
    
    for (int i = 1; i <= new_num; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int input = 5;
    std::cout << special_factorial(input) << std::endl;
    
    return 0;
}
```