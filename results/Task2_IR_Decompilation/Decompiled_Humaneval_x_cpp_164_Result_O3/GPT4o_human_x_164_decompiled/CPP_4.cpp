```cpp
#include <vector>
#include <cmath>
#include <cstdint>

float mean_absolute_deviation(std::vector<float> &vec) {
    size_t n = vec.size();
    if (n == 0) return 0.0f;

    float sum = 0.0f;
    float mean = 0.0f;

    for (size_t i = 0; i < n; ++i) {
        sum += vec[i];
    }
    mean = sum / n;

    float mad = 0.0f;
    for (size_t i = 0; i < n; ++i) {
        mad += std::fabs(vec[i] - mean);
    }

    return mad / n;
}
```