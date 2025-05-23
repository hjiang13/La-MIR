```cpp
#include <string>

bool correct_bracketing(const std::string& str) {
    size_t count = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    return count == 0;
}
```