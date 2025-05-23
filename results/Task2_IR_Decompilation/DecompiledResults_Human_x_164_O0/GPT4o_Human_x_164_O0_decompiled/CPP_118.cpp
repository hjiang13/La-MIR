```cpp
#include <string>
#include <algorithm>

void get_closest_vowel(std::string &result, const std::string &input) {
    result.clear();
    const std::string vowels = "AEIOUaeiou";
    
    if (input.length() < 2) {
        return;
    }

    for (size_t i = 1; i < input.length(); ++i) {
        char current_char = input[i];
        auto found = std::find(vowels.begin(), vowels.end(), current_char);
        if (found != vowels.end()) {
            result += current_char;
            return;
        }
    }
}
```