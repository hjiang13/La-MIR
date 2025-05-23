```cpp
#include <string>

bool is_happy(const std::string& str) {
    size_t length = str.size();
    if (length < 3) {
        return false;
    }

    for (size_t i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}
```