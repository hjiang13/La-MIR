```cpp
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void parse_nested_parens(std::vector<int>& vec, const std::string& str) {
    std::string tempStr;
    tempStr.resize(32);
    
    size_t strLength = str.size();
    size_t index = 0;

    for (size_t i = 0; i < strLength; ++i) {
        char ch = str[i];

        switch (ch) {
            case '(': {
                if (index < vec.size()) {
                    ++vec[index];
                } else {
                    vec.push_back(1);
                }
                break;
            }
            case ')': {
                if (index > 0) {
                    --vec[index];
                } else {
                    throw std::length_error("Excess closing parentheses");
                }
                break;
            }
            default: {
                if (index < vec.size()) {
                    tempStr[index] = ch;
                    ++index;
                }
                break;
            }
        }
    }

    tempStr[index] = '\0';
}
```