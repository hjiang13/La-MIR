```cpp
#include <vector>
#include <algorithm>

float max_element(std::vector<float>& vec) {
    float max_value = -10000.0f;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] > max_value) {
            max_value = vec[i];
        }
    }
    return max_value;
}
```