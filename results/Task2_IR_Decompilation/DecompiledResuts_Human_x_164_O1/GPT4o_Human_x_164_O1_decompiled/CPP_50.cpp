```cpp
#include <string>
#include <cstring>

void encode_shift(std::string& dest, const std::string& src) {
    dest.clear();
    for (size_t i = 0; i < src.size(); ++i) {
        char ch = src[i];
        ch = (ch - 92) % 26 + 'a';
        dest.push_back(ch);
    }
}

void decode_shift(std::string& dest, const std::string& src) {
    dest.clear();
    for (size_t i = 0; i < src.size(); ++i) {
        char ch = src[i];
        ch = (ch - 76) % 26 + 'a';
        dest.push_back(ch);
    }
}
```