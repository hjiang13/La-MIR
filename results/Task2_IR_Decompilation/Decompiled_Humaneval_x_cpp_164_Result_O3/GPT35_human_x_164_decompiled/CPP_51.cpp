```cpp
#include <string>

void remove_vowels(std::string& s) {
    static const char vowels[] = "AEIOUaeiou";
    std::__cxx11::basic_string<char> temp;

    for (char c : s) {
        bool is_vowel = false;
        for (char v : vowels) {
            if (c == v) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            temp += c;
        }
    }

    s = temp;
}
```