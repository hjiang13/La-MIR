```cpp
#include <string>

int vowels_count(std::basic_string<char> *str) {
    std::__cxx11::basic_string<char> vowels = "aeiouAEIOU";

    int count = 0;

    for (char c : *str) {
        if (vowels.find(c) != std::string::npos) {
            count++;
        }
    }

    return count;
}
```