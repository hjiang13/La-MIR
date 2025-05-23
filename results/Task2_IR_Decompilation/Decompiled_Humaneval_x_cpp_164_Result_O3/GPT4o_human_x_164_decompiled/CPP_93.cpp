```cpp
#include <string>
#include <cstring>

void encode(std::string &output, const std::string &input) {
    output.clear();
    for (size_t i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            output += ch - 32;
        } else if (ch >= 'A' && ch <= 'Z') {
            output += ch + 32;
        } else {
            output += ch;
        }
    }
}
```