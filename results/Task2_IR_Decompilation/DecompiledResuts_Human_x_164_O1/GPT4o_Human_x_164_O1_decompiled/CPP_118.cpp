```cpp
#include <string>
#include <cstring>

std::string get_closest_vowel(std::string s) {
    std::string vowels = "AEIOUaeiou";
    std::string result;
    size_t length = s.length();
    
    for (size_t i = 0; i < length; ++i) {
        char current = s[i];
        for (size_t j = 0; j < vowels.length(); ++j) {
            if (current == vowels[j]) {
                result += current;
                break;
            }
        }
    }
    
    return result;
}
```