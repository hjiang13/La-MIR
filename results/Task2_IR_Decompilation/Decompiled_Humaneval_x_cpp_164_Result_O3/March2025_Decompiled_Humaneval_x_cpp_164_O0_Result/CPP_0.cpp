```cpp
#include <vector>
#include <cmath>

bool has_close_elements(const std::vector<float>& vec, float threshold) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (std::abs(vec[i] - vec[j]) < threshold) {
                return true;
            }
        }
    }
    return false;
}
```