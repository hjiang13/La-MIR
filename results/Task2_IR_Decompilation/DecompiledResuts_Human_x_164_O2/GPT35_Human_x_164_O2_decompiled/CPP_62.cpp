```cpp
#include <vector>
#include <stdexcept>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    result.resize(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        result[i] = input[i] * static_cast<float>(i);
    }
}
```