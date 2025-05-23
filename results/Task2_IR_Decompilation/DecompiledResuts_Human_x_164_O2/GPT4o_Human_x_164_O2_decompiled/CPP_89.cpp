```cpp
#include <string>
#include <cstring>

void encrypt(std::string &output, const std::string &input) {
    size_t len = input.length();
    if (len == 0) {
        output = "";
        return;
    }

    output.resize(len);
    for (size_t i = 0; i < len; ++i) {
        output[i] = static_cast<char>((static_cast<unsigned char>(input[i]) - 93) % 26 + 97);
    }
    output[len] = '\0';
}
```