```c++
#include <vector>
#include <cmath>

bool has_close_elements(std::vector<float> &vec, float threshold) {
    float *begin = vec.data();
    float *end = vec.data() + vec.size();

    if (end - begin == 0) {
        return false;
    }

    size_t max_iterations = std::max(end - begin, 1);

    for (size_t i = 1; i < max_iterations; ++i) {
        if (std::fabs(begin[i] - begin[i-1]) < threshold) {
            return true;
        }
    }

    return false;
}
```