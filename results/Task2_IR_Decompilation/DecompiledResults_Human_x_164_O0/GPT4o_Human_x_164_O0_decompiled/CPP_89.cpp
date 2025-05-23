```cpp
#include <string>

std::string encrypt(std::string input) {
    std::string output;
    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];
        char encrypted_char = (ch - 'a' + 4) % 26 + 'a'; // Simple shift encryption
        output += encrypted_char;
    }
    return output;
}
```