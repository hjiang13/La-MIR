```cpp
#include <string>

std::string remove_vowels(std::string input) {
    std::string result;
    const char* vowels = "AEIOUaeiou";
    for (size_t i = 0; i < input.length(); ++i) {
        bool is_vowel = false;
        for (size_t j = 0; j < 10; ++j) {
            if (input[i] == vowels[j]) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            result += input[i];
        }
    }
    return result;
}
```