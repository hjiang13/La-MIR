```cpp
#include <string>
#include <stdexcept>
#include <iostream>

std::string solve(int input) {
    std::string result;
    std::string temp = std::to_string(input);
    int sum = 0;

    for (char c : temp) {
        sum += c - '0';
    }

    while (sum > 0) {
        int remainder = sum % 2;
        result = std::to_string(remainder) + result;
        sum /= 2;
    }

    if (result.empty()) {
        throw std::logic_error("basic_string::_M_construct null not valid");
    }

    return result;
}

int main() {
    int input;
    std::cin >> input;
    try {
        std::string result = solve(input);
        std::cout << result << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```