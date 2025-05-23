```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    size_t input_size = input.size();
    
    if (input_size == 0) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int max_val = input[0];
    result.push_back(max_val);
    
    for (size_t i = 1; i < input_size; ++i) {
        max_val = std::max(max_val, input[i]);
        result.push_back(max_val);
    }
}
```