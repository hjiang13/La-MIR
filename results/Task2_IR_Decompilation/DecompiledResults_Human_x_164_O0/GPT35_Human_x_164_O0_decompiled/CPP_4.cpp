```c
#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &vec) {
    float sum = 0.0;
    int size = vec.size();
    
    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }
    
    float mean = sum / size;
    float abs_diff_sum = 0.0;
    
    for (int i = 0; i < size; i++) {
        float diff = vec[i] - mean;
        abs_diff_sum += std::abs(diff);
    }
    
    float mad = abs_diff_sum / size;
    return mad;
}
```