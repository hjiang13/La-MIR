```cpp
#include <string>

void string_xor(std::string& result, const std::string& str1, const std::string& str2) {
    size_t length1 = str1.length();
    size_t length2 = str2.length();
    
    size_t minLength = length1 < length2 ? length1 : length2;

    for (size_t i = 0; i < minLength; ++i) {
        result.push_back(str1[i] ^ str2[i]);
    }
}
```