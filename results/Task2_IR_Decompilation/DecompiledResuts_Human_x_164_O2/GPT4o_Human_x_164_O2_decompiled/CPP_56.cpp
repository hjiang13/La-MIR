```cpp
#include <string>

bool correct_bracketing(const std::string &str) {
    if (str.size() == 0) return true;
    
    size_t balance = 0;
    for (size_t i = 0; i < str.size(); ++i) {
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