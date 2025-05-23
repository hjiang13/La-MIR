```cpp
#include <string>

void encode_shift(std::string &out, const std::string &in) {
    uint64_t size = 0;
    out = std::string();
    out.resize(in.size());
    size = in.size();
    
    if (size == 0) {
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        out[i] = static_cast<char>((static_cast<uint8_t>(in[i]) + 1) % 256);
    }
}

void decode_shift(std::string &out, const std::string &in) {
    uint64_t size = 0;
    out = std::string();
    out.resize(in.size());
    size = in.size();
    
    if (size == 0) {
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        out[i] = static_cast<char>((static_cast<uint8_t>(in[i]) - 1 + 256) % 256);
    }
}
```