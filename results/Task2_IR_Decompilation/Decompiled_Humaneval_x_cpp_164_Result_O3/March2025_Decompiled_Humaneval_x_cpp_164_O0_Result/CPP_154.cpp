```cpp
#include <string>

bool cycpattern_check(const std::string& str1, const std::string& str2) {
    for (size_t i = 0; i < str2.size(); ++i) {
        std::string substr1 = str2.substr(i);
        std::string substr2 = str2.substr(0, i);
        std::string combined = substr1 + substr2;
        if (str1.find(combined) != std::string::npos) {
            return true;
        }
    }
    return false;
}
```