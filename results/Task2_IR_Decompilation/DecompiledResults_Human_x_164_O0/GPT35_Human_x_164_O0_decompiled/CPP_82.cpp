```cpp
#include <string>

bool prime_length(std::string* str) {
    bool result;
    int length = str->length();
    if (length < 2) {
        result = false;
    } else {
        int divisor = 2;
        while (divisor * divisor <= length) {
            if (length % divisor == 0) {
                result = false;
                break;
            }
            divisor++;
        }
        result = true;
    }
    return result;
}
```