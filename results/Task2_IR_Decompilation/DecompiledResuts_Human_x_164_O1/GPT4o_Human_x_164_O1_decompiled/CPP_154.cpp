```cpp
#include <string>
#include <cstring>

bool cycpattern_check(std::string str1, std::string str2) {
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t i = 0;
    size_t count = 0;

    while (i < len1) {
        if (str1.find(str2, i) != std::string::npos) {
            count++;
            i += len2;
        } else {
            break;
        }
    }

    return count > 0;
}
```