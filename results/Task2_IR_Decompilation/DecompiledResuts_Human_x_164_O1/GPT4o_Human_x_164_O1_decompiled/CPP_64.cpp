```cpp
#include <string>
#include <cstring>

int vowels_count(const std::string &input) {
    const char vowels[] = "aeiouAEIOU";
    int count = 0;
    size_t length = input.length();

    for (size_t i = 0; i < length; ++i) {
        char current = input[i];
        for (size_t j = 0; j < sizeof(vowels) - 1; ++j) {
            if (current == vowels[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}
```