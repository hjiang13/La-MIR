```cpp
#include <string>

int vowels_count(std::__cxx11::basic_string<char> *str) {
    int count = 0;
    for (int i = 0; i < str->size(); i++) {
        char c = (*str)[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}
```