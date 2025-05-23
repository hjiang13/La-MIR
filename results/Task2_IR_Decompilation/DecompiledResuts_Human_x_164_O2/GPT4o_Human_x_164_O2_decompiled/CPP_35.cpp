```cpp
#include <vector>
#include <algorithm>
#include <limits>

float max_element(std::vector<float> const& vec) {
    if (vec.empty()) return -10000.0f;
    
    float max_val = -10000.0f;
    size_t size = vec.size();

    for (size_t i = 0; i < size; ++i) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }
    
    return max_val;
}
```