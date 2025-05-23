```cpp
#include <string>

int count_upper(std::basic_string<char> *str) {
    std::__cxx11::basic_string<char>::_Alloc_hider* alloc = &str->_M_dataplus._M_p;
    char* data = alloc->_M_p;
    const char* vowels = "AEIOU";
    int count = 0;

    for (size_t i = 0; i < str->_M_dataplus._M_string_length; ++i) {
        char ch = data[i];
        if (strchr(vowels, ch) != nullptr) {
            count++;
        }
    }

    return count;
}
```