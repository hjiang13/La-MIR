```cpp
#include <vector>
#include <cmath>

bool has_close_elements(std::vector<float> &vec, float threshold) {
    size_t size = vec.size();
    if (size < 2) {
        return false;
    }

    size_t i = 0;
    while (i < size - 1) {
        float diff = std::fabs(vec[i] - vec[i + 1]);
        if (diff < threshold) {
            return true;
        }
        i++;
    }
    return false;
}
```