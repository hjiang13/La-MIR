```cpp
#include <vector>
#include <cmath>

bool has_close_elements(std::vector<float> &vec, float threshold) {
    if (vec.empty()) {
        return false;
    }
    
    size_t size = vec.size();
    for (size_t i = 1; i < size; ++i) {
        float diff = std::fabs(vec[i] - vec[i - 1]);
        if (diff < threshold) {
            return true;
        }
    }
    return false;
}
```