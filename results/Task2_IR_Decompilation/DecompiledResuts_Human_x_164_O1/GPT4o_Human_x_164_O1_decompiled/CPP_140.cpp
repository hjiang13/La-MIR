```cpp
#include <string>
#include <cstring>
#include <stdexcept>

void fix_spaces(std::string& s) {
    std::string tmp;
    size_t length = s.length();
    size_t space_count = 0;

    for (size_t i = 0; i < length; ++i) {
        if (s[i] == ' ') {
            space_count++;
        } else {
            if (space_count > 0) {
                tmp += ' ';
                space_count = 0;
            }
            tmp += s[i];
        }
    }

    if (space_count > 0) {
        tmp += ' ';
    }

    s = tmp;
}

int main() {
    std::string test = "This    is   a   test   string.";
    fix_spaces(test);
    return 0;
}
```