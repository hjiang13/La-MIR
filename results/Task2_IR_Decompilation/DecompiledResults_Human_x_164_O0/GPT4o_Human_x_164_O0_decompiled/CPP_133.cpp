```cpp
#include <vector>
#include <cmath>

int sum_squares(const std::vector<float>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        float ceil1 = std::ceil(vec[i]);
        float ceil2 = std::ceil(vec[i + 1]);
        sum += static_cast<int>(ceil1 * ceil2);
    }
    return sum;
}
```