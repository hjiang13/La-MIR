```cpp
#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &v) {
    float sum = 0.0f;
    float *data = v.data();
    size_t size = v.size();
    
    if (size == 0) {
        return 0.0f;
    }
    
    for (size_t i = 0; i < size; i++) {
        sum += data[i];
    }
    
    float mean = sum / size;
    sum = 0.0f;
    
    for (size_t i = 0; i < size; i++) {
        sum += std::fabs(data[i] - mean);
    }
    
    return sum / size;
}
```