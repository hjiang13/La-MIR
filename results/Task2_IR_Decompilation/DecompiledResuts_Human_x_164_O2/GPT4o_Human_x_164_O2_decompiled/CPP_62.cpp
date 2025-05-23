```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    size_t inputSize = input.size();
    
    if (inputSize <= 1) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    
    result.resize(inputSize);
    
    for (size_t i = 1; i < inputSize; ++i) {
        float delta = input[i] - input[i - 1];
        result[i - 1] = delta;
    }
}
```