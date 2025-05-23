```cpp
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> sorted_list_sum(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        if (str.length() % 2 == 0) {
            result.push_back(str);
        }
    }
    std::sort(result.begin(), result.end());
    for (size_t i = 1; i < result.size(); ++i) {
        if (result[i].length() < result[i - 1].length()) {
            std::swap(result[i], result[i - 1]);
        }
    }
    return result;
}
```