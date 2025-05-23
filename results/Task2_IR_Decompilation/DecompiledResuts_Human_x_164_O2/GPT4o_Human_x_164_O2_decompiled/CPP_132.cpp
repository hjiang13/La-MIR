```cpp
#include <string>

bool is_nested(const std::string& str) {
    size_t length = str.size();
    if (length == 0) return false;

    size_t count = 0;
    for (size_t i = 0; i < length; ++i) {
        if (str[i] == '[') {
            count++;
        } else if (str[i] == ']') {
            count--;
        }
    }
    return count > 0;
}
```