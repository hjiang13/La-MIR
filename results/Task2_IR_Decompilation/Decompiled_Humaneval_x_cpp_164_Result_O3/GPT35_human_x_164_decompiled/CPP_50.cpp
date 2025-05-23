```cpp
#include <string>

void encode_shift(std::__cxx11::basic_string<char>& s, const std::__cxx11::basic_string<char>& input) {
    s = "";
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = (c - 92) % 26;
        char encoded_char = static_cast<char>(shift + 97);
        s += encoded_char;
    }
}

void decode_shift(std::__cxx11::basic_string<char>& s, const std::__cxx11::basic_string<char>& input) {
    s = "";
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = (c - 76) % 26;
        char decoded_char = static_cast<char>(shift + 97);
        s += decoded_char;
    }
}
```