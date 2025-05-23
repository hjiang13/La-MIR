```cpp
#include <string>

bool correct_bracketing(const std::string& str) {
    int balance = 0;
    for (char ch : str) {
        if (ch == '<') {
            balance++;
        } else if (ch == '>') {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
}
```