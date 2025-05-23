```cpp
#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &vec) {
    float sum = 0.0f;
    int size = vec.size();
    
    for (int i = 0; i < size; ++i) {
        sum += vec[i];
    }
    
    float mean = sum / size;
    float deviation_sum = 0.0f;
    
    for (int i = 0; i < size; ++i) {
        deviation_sum += std::abs(vec[i] - mean);
    }
    
    return deviation_sum / size;
}
```