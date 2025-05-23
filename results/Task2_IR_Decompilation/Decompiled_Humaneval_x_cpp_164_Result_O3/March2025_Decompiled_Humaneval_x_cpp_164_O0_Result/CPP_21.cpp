```cpp
#include <vector>
#include <algorithm>
#include <limits>

void rescale_to_unit(std::vector<float>& result, const std::vector<float>& input) {
    float min_val = std::numeric_limits<float>::max();
    float max_val = std::numeric_limits<float>::lowest();

    for (const auto& val : input) {
        if (val < min_val) {
            min_val = val;
        }
        if (val > max_val) {
            max_val = val;
        }
    }

    result.resize(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        result[i] = (input[i] - min_val) / (max_val - min_val);
    }
}
```