```cpp
#include <string>

std::string encode_shift(const std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        char shifted = ((c - 'a' + 5) % 26) + 'a';
        result += shifted;
    }
    return result;
}

std::string decode_shift(const std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        char shifted = ((c - 'a' + 21) % 26) + 'a';
        result += shifted;
    }
    return result;
}
```