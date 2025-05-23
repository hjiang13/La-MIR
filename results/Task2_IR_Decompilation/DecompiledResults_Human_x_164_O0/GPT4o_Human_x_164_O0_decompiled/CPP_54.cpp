```cpp
#include <string>
#include <iterator>

bool same_chars(const std::string& str1, const std::string& str2) {
    size_t length1 = str1.length();
    size_t length2 = str2.length();

    if (length1 != length2) {
        return false;
    }

    for (size_t i = 0; i < length1; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}
```