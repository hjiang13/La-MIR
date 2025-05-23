```cpp
#include <string>
#include <algorithm>

void encode(std::string &output, const std::string &input) {
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            output += c - 32;
        } else if (c >= 'A' && c <= 'Z') {
            output += c + 32;
        } else {
            output += c;
        }
    }
}
```