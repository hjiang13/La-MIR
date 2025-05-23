```cpp
#include <string>

std::string string_xor(const std::string& str1, const std::string& str2) {
    std::string result;
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t i = 0;

    while (i < len1 && i < len2) {
        if (str1[i] == str2[i]) {
            result += '0';
        } else {
            result += '1';
        }
        ++i;
    }

    while (i < len1) {
        result += str1[i];
        ++i;
    }

    while (i < len2) {
        result += str2[i];
        ++i;
    }

    return result;
}
```