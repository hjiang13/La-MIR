```cpp
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

std::vector<float> find_closest_elements(const std::vector<float>& input) {
    std::vector<float> result;
    if (input.size() < 2) {
        return result;
    }

    float min_diff = std::abs(input[0] - input[1]);
    result = {input[0], input[1]};

    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = i + 1; j < input.size(); ++j) {
            float diff = std::abs(input[i] - input[j]);
            if (diff < min_diff) {
                min_diff = diff;
                result = {input[i], input[j]};
            }
        }
    }

    if (result[0] > result[1]) {
        std::swap(result[0], result[1]);
    }

    return result;
}
```