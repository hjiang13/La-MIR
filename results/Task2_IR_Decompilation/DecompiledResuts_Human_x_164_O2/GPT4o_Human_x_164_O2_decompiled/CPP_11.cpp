```cpp
#include <string>

void string_xor(std::string &result, const std::string &a, const std::string &b) {
    result.clear();
    size_t length_a = a.size();
    size_t length_b = b.size();
    
    size_t min_length = std::min(length_a, length_b);
    for (size_t i = 0; i < min_length; ++i) {
        result.push_back(a[i] ^ b[i]);
    }
    
    if (length_a > min_length) {
        result.append(a.substr(min_length));
    } else if (length_b > min_length) {
        result.append(b.substr(min_length));
    }
}
```