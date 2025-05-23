```cpp
#include <string>
#include <cstdlib>

int fruit_distribution(const std::string& input, int value) {
    long num1 = 0, num2 = 0;
    std::string temp1, temp2;
    
    if (input.empty()) {
        return value;
    }

    const char* str1 = input.c_str();
    num1 = strtol(str1, nullptr, 10);
    
    const char* str2 = input.c_str();
    num2 = strtol(str2, nullptr, 10);
    
    int sum = static_cast<int>(num1) + static_cast<int>(num2);
    int result = value - sum;
    
    return result;
}
```