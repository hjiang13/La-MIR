```cpp
#include <string>

void solve(std::string& result, const std::string& input) {
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        } else if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }
        result += c;
    }
}
```