```cpp
#include <string>

bool check_if_last_char_is_a_letter(const std::string& str) {
    size_t length = str.size();
    if (length == 0) {
        return false;
    }
    char lastChar = str[length - 1];
    return (lastChar >= 'A' && lastChar <= 'Z') || (lastChar >= 'a' && lastChar <= 'z');
}
```