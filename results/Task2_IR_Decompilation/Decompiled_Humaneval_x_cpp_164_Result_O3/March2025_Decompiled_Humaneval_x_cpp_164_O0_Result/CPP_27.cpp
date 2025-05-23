```cpp
#include <string>
#include <cctype>

std::string filp_case(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (std::islower(c)) {
            result += std::toupper(c);
        } else if (std::isupper(c)) {
            result += std::tolower(c);
        } else {
            result += c;
        }
    }
    return result;
}
```