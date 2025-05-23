```cpp
#include <string>

void encode_shift(std::string& out, const std::string& in) {
    out.clear();
    for (size_t i = 0; i < in.length(); ++i) {
        char c = in[i];
        c = (c - 'a' + 5) % 26 + 'a';
        out += c;
    }
}

void decode_shift(std::string& out, const std::string& in) {
    out.clear();
    for (size_t i = 0; i < in.length(); ++i) {
        char c = in[i];
        c = (c - 'a' + 21) % 26 + 'a';
        out += c;
    }
}
```