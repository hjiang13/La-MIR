```cpp
#include <string>

int is_bored(const std::string& str) {
    size_t length = str.size();
    if (length == 0) {
        return 0;
    }

    int count = 0;
    for (size_t i = 0; i < length; ++i) {
        char ch = str[i];
        if (ch == ' ') {
            count++;
        }
        else if (ch == 'I') {
            count++;
        }
        else if (ch == 'F' || ch == 'G' || ch == 'A') {
            count++;
        }
    }
    return count;
}
```