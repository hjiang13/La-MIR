```cpp
#include <string>
#include <cstring>

void fix_spaces(std::string& s) {
    size_t len = s.length();
    if (len == 0) {
        return;
    }

    std::string result;
    result.reserve(len);

    size_t space_count = 0;
    for (size_t i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            if (space_count == 0) {
                result += ' ';
            }
            space_count++;
        } else {
            result += s[i];
            space_count = 0;
        }
    }

    s = result;
}
```