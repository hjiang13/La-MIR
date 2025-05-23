```cpp
#include <string>
#include <vector>

std::string longest(std::string &result, const std::vector<std::string> &vec) {
    std::string current;
    size_t max_length = 0;

    for (const auto &str : vec) {
        if (str.length() > max_length) {
            max_length = str.length();
            current = str;
        }
    }

    result = current;
    return result;
}
```