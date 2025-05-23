```cpp
#include <string>
#include <cstring>
#include <iostream>

std::string get_closest_vowel(std::string str) {
    std::string result;
    const char* vowels = "AEIOUaeiou";
    size_t len = str.size();
    
    if (len > 1) {
        for (size_t i = 0; i < len; ++i) {
            if (strchr(vowels, str[i]) != nullptr) {
                result += str[i];
            }
        }
    }

    return result;
}

int main() {
    std::string input = "Hello World";
    std::string closestVowel = get_closest_vowel(input);
    std::cout << "Closest vowels: " << closestVowel << std::endl;
    return 0;
}
```