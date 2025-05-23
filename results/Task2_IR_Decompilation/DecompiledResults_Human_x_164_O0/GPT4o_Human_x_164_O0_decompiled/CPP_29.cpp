```cpp
#include <vector>
#include <string>

void filter_by_prefix(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& prefix) {
    for (size_t i = 0; i < input.size(); ++i) {
        std::string item = input[i];
        if (item.substr(0, prefix.length()) == prefix) {
            result.push_back(item);
        }
    }
}
```