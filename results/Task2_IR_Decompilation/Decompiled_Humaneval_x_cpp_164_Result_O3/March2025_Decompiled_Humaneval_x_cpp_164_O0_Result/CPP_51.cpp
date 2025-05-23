```cpp
#include <string>
#include <algorithm>

std::string remove_vowels(const std::string& input) {
    std::string vowels = "AEIOUaeiou";
    std::string result;
    for (char c : input) {
        if (std::find(vowels.begin(), vowels.end(), c) == vowels.end()) {
            result += c;
        }
    }
    return result;
}
```