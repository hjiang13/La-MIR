```cpp
#include <string>

bool cycpattern_check(std::basic_string<char>& s1, std::basic_string<char>& s2) {
    if (s2.size() == 0) {
        return false;
    }

    std::basic_string<char> temp;
    if (s2.size() > 15) {
        temp = s1.substr(0, 0);
    } else {
        temp = s1.substr(0, s2.size());
    }

    if (temp == s2) {
        return true;
    }

    if (s1.find(s2.c_str(), 0, s2.size()) != std::string::npos) {
        return true;
    }

    return false;
}
```