```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>

std::vector<std::vector<int>> get_row(const std::vector<std::vector<int>>& input, int value) {
    std::vector<std::vector<int>> result;
    for (const auto& row : input) {
        if (!row.empty() && row.back() == value) {
            result.push_back({row.size() - 1, static_cast<int>(row.size() - 1)});
        }
    }
    return result;
}
```