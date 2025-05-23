```cpp
#include <string>

std::string encrypt(const std::string& input) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        char encryptedChar = ((c + 4 - 97) % 26) + 97;
        result += encryptedChar;
    }
    return result;
}
```