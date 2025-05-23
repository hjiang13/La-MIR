```cpp
#include <vector>
#include <string>

std::vector<std::string> filter_by_substring(const std::vector<std::string>& input, const std::string& substring) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        if (str.find(substring) != std::string::npos) {
            result.push_back(str);
        }
    }
    return result;
}
```