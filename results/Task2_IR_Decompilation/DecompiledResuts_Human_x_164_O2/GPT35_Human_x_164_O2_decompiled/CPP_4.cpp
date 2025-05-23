```c
#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &vec) {
    float sum = 0.0;
    float mean = 0.0;
    int size = vec.size();

    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }

    mean = sum / size;

    float mad = 0.0;
    for (int i = 0; i < size; i++) {
        mad += std::fabs(vec[i] - mean);
    }

    mad /= size;

    return mad;
}
```