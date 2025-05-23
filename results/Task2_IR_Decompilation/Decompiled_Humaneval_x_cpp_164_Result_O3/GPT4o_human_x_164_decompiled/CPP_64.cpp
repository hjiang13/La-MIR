```cpp
#include <string>
#include <cstring>

int vowels_count(const std::string& str) {
    const char* vowels = "aeiouAEIOU";
    int count = 0;
    size_t length = str.length();

    for (size_t i = 0; i < length; ++i) {
        char ch = str[i];
        if (strchr(vowels, ch) != nullptr) {
            count++;
        }
    }
    return count;
}
```