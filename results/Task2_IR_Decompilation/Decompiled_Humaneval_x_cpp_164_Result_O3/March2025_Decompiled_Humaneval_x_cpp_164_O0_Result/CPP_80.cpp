```cpp
#include <string>

bool is_happy(const std::string& str) {
    if (str.length() < 3) {
        return false;
    }

    for (size_t i = 2; i < str.length(); ++i) {
        if (str[i] == str[i - 1] || str[i] == str[i - 2]) {
            return false;
        }
    }

    return true;
}
```