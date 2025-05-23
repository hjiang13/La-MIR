```cpp
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

std::vector<std::string> filter_by_prefix(const std::vector<std::string>& input, const std::string& prefix) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        if (str.substr(0, prefix.length()) == prefix) {
            result.push_back(str);
        }
    }
    return result;
}
```