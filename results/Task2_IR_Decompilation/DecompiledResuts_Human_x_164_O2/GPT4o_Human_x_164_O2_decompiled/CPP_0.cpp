```cpp
#include <vector>
#include <cmath>

bool has_close_elements(std::vector<float> const& vec, float epsilon) {
    size_t size = vec.size();
    if (size <= 1) return false;

    for (size_t i = 1; i < size; ++i) {
        float diff = std::fabs(vec[i] - vec[i - 1]);
        if (diff < epsilon) {
            return true;
        }
    }
    return false;
}
```