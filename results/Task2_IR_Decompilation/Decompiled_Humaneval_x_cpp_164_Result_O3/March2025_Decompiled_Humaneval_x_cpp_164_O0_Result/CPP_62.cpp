```cpp
#include <vector>
#include <stdexcept>
#include <algorithm>

std::vector<float> derivative(const std::vector<float>& input) {
    std::vector<float> result;
    for (size_t i = 1; i < input.size(); ++i) {
        result.push_back(static_cast<float>(i) * input[i]);
    }
    return result;
}
```