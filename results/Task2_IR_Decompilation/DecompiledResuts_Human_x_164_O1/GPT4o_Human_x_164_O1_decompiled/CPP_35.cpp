```cpp
#include <vector>
#include <algorithm>

float max_element(std::vector<float> &vec) {
    if (vec.empty()) {
        return -1e4; // Return a sentinel value for empty vector
    }

    float max_val = -1e4;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }
    return max_val;
}
```