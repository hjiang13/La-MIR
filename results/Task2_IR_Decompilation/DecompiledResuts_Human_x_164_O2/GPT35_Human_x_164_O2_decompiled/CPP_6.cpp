```cpp
#include <vector>
#include <string>

void parse_nested_parens(std::vector<int>& result, std::string& input) {
    std::__cxx11::basic_string<char> temp_str;
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '(') {
            result.push_back(i);
        } else if (input[i] == ')') {
            if (!result.empty()) {
                result.pop_back();
            }
        }
    }
}

int main() {
    std::vector<int> result;
    std::__cxx11::basic_string<char> input = "((()))";
    parse_nested_parens(result, input);
    return 0;
}
```