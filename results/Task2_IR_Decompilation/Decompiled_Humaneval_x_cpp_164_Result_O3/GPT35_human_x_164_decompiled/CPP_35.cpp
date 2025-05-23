```c
#include <vector>
#include <algorithm>

float max_element(std::vector<float> &vec) {
    if (vec.empty()) {
        return -10000.0f;
    }

    float max_val = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }

    return max_val;
}
```