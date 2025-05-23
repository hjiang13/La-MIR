```cpp
#include <vector>
#include <algorithm>

float max_element(std::vector<float> &vec) {
    float max_val = -1e4;
    size_t size = vec.size();
    
    if (size == 0) return max_val;

    for (size_t i = 0; i < size; ++i) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }

    return max_val;
}
```