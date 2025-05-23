```cpp
#include <vector>
#include <string>
#include <stdexcept>

void parse_nested_parens(std::vector<int>& vec, const std::string& str) {
    size_t i = 0;
    size_t length = str.length();
    bool is_error = false;

    while (i < length) {
        char ch = str[i++];
        if (ch == '(') {
            vec.push_back(1);
        } else if (ch == ')') {
            if (vec.empty() || vec.back() != 1) {
                is_error = true;
                break;
            }
            vec.pop_back();
        }
    }

    if (!vec.empty() || is_error) {
        throw std::length_error("Mismatched parentheses");
    }
}

int main() {
    std::vector<int> vec;
    std::string input = "((()))"; // Example input
    try {
        parse_nested_parens(vec, input);
    } catch (const std::length_error& e) {
        return 1;
    }
    return 0;
}
```