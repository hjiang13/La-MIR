```cpp
#include <string>

bool check_if_last_char_is_a_letter(const std::string& str) {
    size_t len = str.size();
    if (len == 0) return false;

    char last_char = str[len - 1];
    return (last_char >= 'A' && last_char <= 'Z') || (last_char >= 'a' && last_char <= 'z');
}
```