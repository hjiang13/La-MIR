```cpp
#include <vector>
#include <stdexcept>
#include <cstring>
#include <cstdlib>
#include <algorithm>

void compare(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    result.clear();
    
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    
    if (size1 != size2) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    for (size_t i = 0; i < size1; ++i) {
        int diff = std::abs(vec1[i] - vec2[i]);
        result.push_back(diff);
    }
}
```