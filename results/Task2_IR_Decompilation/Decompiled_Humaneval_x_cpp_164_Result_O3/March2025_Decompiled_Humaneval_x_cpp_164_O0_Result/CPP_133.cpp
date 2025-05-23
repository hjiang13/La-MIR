```cpp
#include <vector>
#include <cmath>

int sum_squares(std::vector<float> &vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        float ceil_val = std::ceil(vec[i]);
        sum += static_cast<int>(ceil_val * ceil_val);
    }
    return sum;
}
```