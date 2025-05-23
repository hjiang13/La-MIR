```cpp
#include <vector>
#include <algorithm>
#include <limits>

void rescale_to_unit(std::vector<float>& vec) {
    float min_val = 1.0e+05f;
    float max_val = -1.0e+05f;

    for (size_t i = 0; i < vec.size(); ++i) {
        float value = vec[i];
        if (value < min_val) {
            min_val = value;
        }
        if (value > max_val) {
            max_val = value;
        }
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        float value = vec[i];
        vec[i] = (value - min_val) / (max_val - min_val);
    }
}
```