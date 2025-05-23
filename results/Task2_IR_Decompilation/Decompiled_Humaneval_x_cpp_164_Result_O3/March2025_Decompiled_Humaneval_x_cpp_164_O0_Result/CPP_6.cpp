```cpp
#include <string>
#include <vector>
#include <stdexcept>

std::vector<int> parse_nested_parens(const std::string& input) {
    std::vector<int> result;
    std::string current;
    int depth = 0;
    int max_depth = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c == '(') {
            ++depth;
            if (depth > max_depth) {
                max_depth = depth;
            }
            current += c;
        } else if (c == ')') {
            --depth;
            current += c;
            if (depth == 0) {
                result.push_back(max_depth);
                current.clear();
                max_depth = 0;
            }
        } else {
            current += c;
        }
    }

    if (!current.empty()) {
        throw std::runtime_error("Unmatched parentheses");
    }

    return result;
}
```