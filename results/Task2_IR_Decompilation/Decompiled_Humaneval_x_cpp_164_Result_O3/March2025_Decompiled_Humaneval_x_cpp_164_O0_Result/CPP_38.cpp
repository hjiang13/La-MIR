```cpp
#include <string>

std::string encode_cyclic(const std::string& input) {
    std::string result;
    std::string temp;
    for (size_t i = 0; i < input.length(); i += 3) {
        temp = input.substr(i, 3);
        if (temp.length() == 3) {
            std::string shifted = temp.substr(1) + temp[0];
            result += shifted;
        } else {
            result += temp;
        }
    }
    return result;
}

std::string decode_cyclic(const std::string& input) {
    std::string result;
    std::string temp;
    for (size_t i = 0; i < input.length(); i += 3) {
        temp = input.substr(i, 3);
        if (temp.length() == 3) {
            std::string shifted = temp[2] + temp.substr(0, 2);
            result += shifted;
        } else {
            result += temp;
        }
    }
    return result;
}
```