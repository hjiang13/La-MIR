```cpp
#include <string>
#include <cstring>

void remove_vowels(std::string& result, const std::string& input) {
    result.clear();
    for (char c : input) {
        if (!(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
              c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            result += c;
        }
    }
}
```