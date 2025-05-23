```cpp
#include <string>

void encode_cyclic(std::string &out, const std::string &in) {
    size_t len = in.length();
    int iterations = (len + 2) / 3;
    out.clear();

    for (int i = 0; i < iterations; ++i) {
        size_t start = i * 3;
        if (start < len) {
            out += in.substr(start, 3);
        }
    }
}

void decode_cyclic(std::string &out, const std::string &in) {
    size_t len = in.length();
    int iterations = (len + 2) / 3;
    out.clear();

    for (int i = 0; i < iterations; ++i) {
        size_t start = i * 3;
        if (start < len) {
            out += in.substr(start, 3);
        }
    }
}
```