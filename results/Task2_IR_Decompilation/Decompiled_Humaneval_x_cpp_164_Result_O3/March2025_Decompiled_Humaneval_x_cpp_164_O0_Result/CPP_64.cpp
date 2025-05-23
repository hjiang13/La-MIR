```cpp
#include <string>

int vowels_count(const std::string& input) {
    const std::string vowels = "aeiouAEIOU";
    int count = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        if (vowels.find(input[i]) != std::string::npos) {
            ++count;
        }
    }
    if (!input.empty() && (input.back() == 'y' || input.back() == 'Y')) {
        ++count;
    }
    return count;
}
```