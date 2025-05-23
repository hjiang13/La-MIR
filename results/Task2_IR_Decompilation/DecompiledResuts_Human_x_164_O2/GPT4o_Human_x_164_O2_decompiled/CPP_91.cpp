```cpp
#include <string>

int is_bored(const std::string &str) {
    size_t size = str.size();
    if (size == 0) return 0;

    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        char c = str[i];
        if (c == ' ') {
            count++;
        }
        if (c == 'I') {
            count++;
        }
        if (c == 'F' || c == '?') {
            break;
        }
    }
    return count;
}
```