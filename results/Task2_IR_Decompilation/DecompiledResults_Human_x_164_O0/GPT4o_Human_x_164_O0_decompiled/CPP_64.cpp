```cpp
#include <string>

int vowels_count(const std::string& str) {
    int count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}
```