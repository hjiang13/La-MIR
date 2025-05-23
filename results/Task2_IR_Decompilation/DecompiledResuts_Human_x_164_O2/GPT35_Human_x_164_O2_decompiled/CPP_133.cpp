```c++
#include <vector>
#include <cmath>

int sum_squares(std::vector<float> *v) {
    float *begin = &((*v)[0]);
    float *end = &((*v)[0]);

    long long diff = (long long)begin - (long long)end;
    if (diff == 0) {
        return 0;
    }

    long long num_elements = diff >> 2;
    num_elements = std::max(num_elements, (long long)1);
    bool odd_num_elements = (num_elements & 1) == 1;
    
    float sum = 0.0f;
    for (int i = 0; i < num_elements; i++) {
        float value = std::ceil(*(end + i));
        float squared_value = value * value;
        sum += squared_value;
    }

    if (odd_num_elements) {
        float value = std::ceil(*(end + num_elements));
        float squared_value = value * value;
        sum += squared_value;
    }

    return static_cast<int>(sum);
}
```