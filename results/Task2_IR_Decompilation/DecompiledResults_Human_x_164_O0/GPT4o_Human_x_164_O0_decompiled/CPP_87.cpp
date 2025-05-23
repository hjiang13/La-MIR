```cpp
#include <vector>
#include <stdexcept>

void get_row(std::vector<std::vector<int>>& result, const std::vector<std::vector<int>>& source, int index) {
    if (index < 0 || index >= source.size()) {
        throw std::out_of_range("Index out of range");
    }
    result.clear();
    result.reserve(source[index].size());
    for (const auto& value : source[index]) {
        result.push_back(value);
    }
}
```