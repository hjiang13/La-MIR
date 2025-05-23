```cpp
#include <string>
#include <iostream>

int digitSum(std::string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            sum += c - 'a' + 1;
        }
    }
    return sum;
}

int main() {
    std::string input = "example_string";
    int result = digitSum(input);
    std::cout << "Digit sum of input string is: " << result << std::endl;
    return 0;
}
```