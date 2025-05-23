```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<float> get_positive(const std::vector<float>& input) {
    std::vector<float> result;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] > 0.0f) {
            result.push_back(input[i]);
        }
    }
    return result;
}
```