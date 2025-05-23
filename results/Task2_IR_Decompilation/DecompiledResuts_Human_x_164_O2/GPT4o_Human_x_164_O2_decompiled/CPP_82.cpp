```cpp
#include <string>

bool prime_length(const std::string& str) {
    size_t length = str.size();
    if (length < 2) {
        return false;
    }
    if (length < 4) {
        return true;
    }

    int n = 2;
    while (true) {
        int remainder = length % n;
        bool is_divisible = (remainder == 0);
        n += 1;
        if (is_divisible) {
            return true;
        }
        int square = n * n;
        if (square > length) {
            break;
        }
    }
    return false;
}
```