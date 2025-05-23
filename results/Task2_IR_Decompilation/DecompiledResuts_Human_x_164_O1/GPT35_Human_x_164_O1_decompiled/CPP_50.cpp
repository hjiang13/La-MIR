```cpp
#include <string>

void encode_shift(std::__cxx11::basic_string<char>& s, std::__cxx11::basic_string<char>& input) {
    s.clear();
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = static_cast<int>(c) - 92;
        int result = (shift % 26) + 97;
        s.push_back(static_cast<char>(result));
    }
}

void decode_shift(std::__cxx11::basic_string<char>& s, std::__cxx11::basic_string<char>& input) {
    s.clear();
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = static_cast<int>(c) - 76;
        int result = (shift % 26) + 97;
        s.push_back(static_cast<char>(result));
    }
}
```