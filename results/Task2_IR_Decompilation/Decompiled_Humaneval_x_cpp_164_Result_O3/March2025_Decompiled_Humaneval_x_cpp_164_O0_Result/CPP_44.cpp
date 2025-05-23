```cpp
#include <string>
#include <stdexcept>

std::string change_base(int num, int base) {
    if (base <= 0) {
        throw std::logic_error("basic_string::_M_construct null not valid");
    }
    std::string result;
    while (num > 0) {
        int remainder = num % base;
        result = std::to_string(remainder) + result;
        num /= base;
    }
    return result;
}
```