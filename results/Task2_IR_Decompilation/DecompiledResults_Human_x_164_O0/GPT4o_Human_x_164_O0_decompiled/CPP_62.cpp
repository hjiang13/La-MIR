```cpp
#include <vector>
#include <stdexcept>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    size_t size = input.size();
    for (size_t i = 0; i < size; ++i) {
        float value = input[i];
        result.push_back(value * static_cast<float>(i + 1));
    }
}
```