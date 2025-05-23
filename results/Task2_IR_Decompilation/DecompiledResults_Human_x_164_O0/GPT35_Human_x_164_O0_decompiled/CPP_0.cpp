```c++
#include <vector>
#include <cmath>

bool has_close_elements(std::vector<float>& vec, float val) {
    bool result = false;
    float diff_threshold = val;

    int i = 0;
    for (; i < vec.size(); ++i) {
        if (std::abs(vec[i] - vec[i + 1]) < diff_threshold) {
            result = true;
            break;
        }
    }

    return result;
}
```