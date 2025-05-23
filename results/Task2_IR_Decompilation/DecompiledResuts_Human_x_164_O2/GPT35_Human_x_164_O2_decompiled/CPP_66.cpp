```cpp
#include <string>
#include <iostream>

int digitSum(std::basic_string<char> str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            sum += c - 'a' + 1;
        } else if (c >= 'A' && c <= 'Z') {
            sum += c - 'A' + 1;
        }
    }
    return sum;
}

int main() {
    std::basic_string<char> str = "Hello, World!";
    int result = digitSum(str);
    std::cout << "Digit sum of string is: " << result << std::endl;
    return 0;
}
```