```cpp
#include <string>

bool is_happy(const std::string& str) {
    size_t length = str.size();
    if (length < 3) return false;

    char first = str[1];
    for (size_t i = 2; i < length; ++i) {
        if (str[i] != first) {
            return false;
        }
    }
    return true;
}
```