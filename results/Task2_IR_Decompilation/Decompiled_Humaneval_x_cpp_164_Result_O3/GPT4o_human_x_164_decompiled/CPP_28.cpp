```cpp
#include <string>
#include <vector>

void concatenate(std::string &result, const std::vector<std::string> &strings) {
    size_t total_length = 0;
    for (const auto &str : strings) {
        total_length += str.size();
    }

    if (total_length > 0) {
        result.reserve(total_length);
        for (const auto &str : strings) {
            result.append(str);
        }
    }
}
```