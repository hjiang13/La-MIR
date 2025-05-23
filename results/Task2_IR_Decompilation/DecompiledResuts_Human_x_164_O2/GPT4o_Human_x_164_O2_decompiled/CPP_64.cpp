```cpp
#include <string>

int vowels_count(const std::string& str) {
    const char* vowels = "aeiouAEIOU";
    int count = 0;

    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];
        for (size_t j = 0; j < 10; ++j) {
            if (ch == vowels[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}
```