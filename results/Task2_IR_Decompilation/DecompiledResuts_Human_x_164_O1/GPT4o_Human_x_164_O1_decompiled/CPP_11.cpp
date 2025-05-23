```cpp
#include <string>

void string_xor(std::string &result, const std::string &str1, const std::string &str2) {
    result.clear();
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    size_t minLength = std::min(len1, len2);
    
    for (size_t i = 0; i < minLength; ++i) {
        result.push_back(str1[i] ^ str2[i]);
    }
    
    if (len1 > minLength) {
        result.append(str1.substr(minLength));
    } else if (len2 > minLength) {
        result.append(str2.substr(minLength));
    }
    
    result.push_back('\0');
}
```