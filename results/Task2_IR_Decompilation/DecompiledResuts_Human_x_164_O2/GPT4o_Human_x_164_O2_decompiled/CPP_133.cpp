```cpp
#include <vector>
#include <cmath>

int sum_squares(std::vector<float> vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        float value = std::ceil(vec[i]);
        sum += value * value;
    }
    return sum;
}
```