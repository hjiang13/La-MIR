```cpp
#include <string>

bool correct_bracketing(const std::string& str) {
    size_t length = str.size();
    if (length == 0) return false;

    int balance = 0;
    for (size_t i = 0; i < length; ++i) {
        char ch = str[i];
        if (ch == '<') {
            balance++;
        } else if (ch == '>') {
            balance--;
        }
        if (balance < 0) return false;
    }
    return balance == 0;
}
```