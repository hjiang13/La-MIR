```cpp
#include <vector>
#include <limits>

float max_element(const std::vector<float>& vec) {
    float max_val = -10000.0f;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (max_val < vec[i]) {
            max_val = vec[i];
        }
    }
    return max_val;
}
```