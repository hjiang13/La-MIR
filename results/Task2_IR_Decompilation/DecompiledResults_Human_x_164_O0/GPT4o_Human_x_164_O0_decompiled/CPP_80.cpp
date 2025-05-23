```cpp
#include <string>

bool is_happy(const std::string& str) {
    if (str.length() < 3) {
        return false;
    }

    for (size_t i = 1; i < str.length() - 1; ++i) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}
```