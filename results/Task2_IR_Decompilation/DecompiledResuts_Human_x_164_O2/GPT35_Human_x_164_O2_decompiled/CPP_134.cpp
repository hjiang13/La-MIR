```c++
#include <string>

bool check_if_last_char_is_a_letter(std::basic_string<char> &str) {
    if (str.empty()) {
        return false;
    }

    size_t len = str.size();
    char last_char = str[len - 1];

    if (last_char < 'A') {
        return false;
    }

    if (last_char > 'Z') {
        if (last_char < 'a') {
            return false;
        }

        if (last_char > 'z') {
            return false;
        }
    }

    return true;
}
```