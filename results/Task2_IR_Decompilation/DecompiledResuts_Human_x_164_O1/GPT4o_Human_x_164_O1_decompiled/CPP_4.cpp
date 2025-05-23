```cpp
#include <vector>
#include <cmath>
#include <algorithm>

float mean_absolute_deviation(std::vector<float> &vec) {
    if (vec.empty()) return 0.0f;
    
    size_t n = vec.size();
    float sum = 0.0f;

    for (size_t i = 0; i < n; ++i) {
        sum += vec[i];
    }
    
    float mean = sum / n;
    float mad_sum = 0.0f;

    for (size_t i = 0; i < n; ++i) {
        mad_sum += std::fabs(vec[i] - mean);
    }

    return mad_sum / n;
}
```