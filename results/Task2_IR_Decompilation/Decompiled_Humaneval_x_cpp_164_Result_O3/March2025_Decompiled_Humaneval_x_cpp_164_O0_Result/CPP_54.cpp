```cpp
#include <string>
#include <algorithm>

bool same_chars(const std::string& str1, const std::string& str2) {
    for (size_t i = 0; i < str1.length(); ++i) {
        if (std::find(str2.begin(), str2.end(), str1[i]) == str2.end()) {
            return false;
        }
    }
    for (size_t i = 0; i < str2.length(); ++i) {
        if (std::find(str1.begin(), str1.end(), str2[i]) == str1.end()) {
            return false;
        }
    }
    return true;
}
```