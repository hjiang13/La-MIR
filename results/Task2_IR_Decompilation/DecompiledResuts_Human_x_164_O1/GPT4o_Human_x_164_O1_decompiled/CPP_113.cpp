```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cassert>

void odd_count(std::vector<std::string>& output, const std::vector<std::string>& input) {
    output.clear();
    int odd_count = 0;

    for (const auto& str : input) {
        for (char ch : str) {
            if (isdigit(ch) && (ch - '0') % 2 == 1) {
                odd_count++;
            }
        }
    }

    output.push_back("The number of odd elements in the string is: " + std::to_string(odd_count));
}

int main() {
    std::vector<std::string> input = {"123", "456", "789"};
    std::vector<std::string> output;

    odd_count(output, input);

    for (const auto& str : output) {
        std::cout << str << std::endl;
    }

    return 0;
}
```