```cpp
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

void compare(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    result.clear();

    if (vec1.empty() || vec2.empty()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    size_t size = std::min(vec1.size(), vec2.size());
    for (size_t i = 0; i < size; ++i) {
        int diff = std::abs(vec1[i] - vec2[i]);
        result.push_back(diff);
    }

    if (result.size() > vec1.size()) {
        throw std::length_error("vector::_M_realloc_insert");
    }
}
```