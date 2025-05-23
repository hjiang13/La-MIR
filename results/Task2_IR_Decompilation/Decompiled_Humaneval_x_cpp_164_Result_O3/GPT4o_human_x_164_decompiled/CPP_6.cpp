```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>

void parse_nested_parens(std::vector<int>& vec, const std::string& str) {
    std::string temp_str;
    size_t length = str.size();
    size_t index = 0;

    while (index < length) {
        char c = str[index];

        switch (c) {
            case '(':
                vec.push_back(1);  // Increment some counter or state
                break;
            case ')':
                if (vec.empty()) {
                    throw std::length_error("Too many closing parentheses");
                }
                vec.pop_back();  // Decrement some counter or state
                break;
            default:
                temp_str += c;
                break;
        }
        ++index;
    }

    if (!vec.empty()) {
        throw std::length_error("Too many opening parentheses");
    }
}
```