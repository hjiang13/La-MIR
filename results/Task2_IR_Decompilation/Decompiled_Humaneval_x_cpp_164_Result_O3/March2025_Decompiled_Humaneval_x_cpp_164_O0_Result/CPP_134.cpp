```cpp
#include <string>

bool check_if_last_char_is_a_letter(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    char lastChar = str.back();
    if ((lastChar >= 'A' && lastChar <= 'Z') || (lastChar >= 'a' && lastChar <= 'z')) {
        if (str.length() == 1) {
            return true;
        }

        char secondLastChar = str[str.length() - 2];
        if ((secondLastChar >= 'A' && secondLastChar <= 'Z') || (secondLastChar >= 'a' && secondLastChar <= 'z')) {
            return false;
        } else {
            return true;
        }
    }

    return false;
}
```