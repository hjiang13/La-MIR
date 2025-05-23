```c++
#include <vector>
#include <algorithm>

bool has_close_elements(std::vector<float> &vec, float threshold) {
    size_t size = vec.size();
    
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            float diff = std::abs(vec[i] - vec[j]);
            if (diff < threshold) {
                return true;
            }
        }
    }
    
    return false;
}
```