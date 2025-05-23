```cpp
#include <string>

bool prime_length(const std::string &s) {
    size_t length = s.size();
    if (length < 2) return false;
    if (length < 4) return true;

    for (int i = 2; i < length; i++) {
        if (length % i == 0) return false;
    }
    return true;
}
```