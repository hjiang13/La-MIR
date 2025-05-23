```cpp
#include <string>
#include <cstring>

void encode_shift(std::string &out, const std::string &in) {
    size_t length = in.size();
    out.resize(length);
    for (size_t i = 0; i < length; ++i) {
        char c = in[i];
        c = (c + 26 - 92) % 26 + 'a';
        out[i] = c;
    }
}

void decode_shift(std::string &out, const std::string &in) {
    size_t length = in.size();
    out.resize(length);
    for (size_t i = 0; i < length; ++i) {
        char c = in[i];
        c = (c - 'a' + 76) % 26;
        out[i] = c;
    }
}
```