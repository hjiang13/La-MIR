```cpp
#include <vector>
#include <cmath>
#include <cstddef>

bool has_close_elements(const std::vector<float>& vec, float threshold) {
    size_t size = vec.size();
    for (size_t i = 0; i < size - 1; ++i) {
        float diff = std::fabs(vec[i] - vec[i + 1]);
        if (diff < threshold) {
            return true;
        }
    }
    return false;
}
```