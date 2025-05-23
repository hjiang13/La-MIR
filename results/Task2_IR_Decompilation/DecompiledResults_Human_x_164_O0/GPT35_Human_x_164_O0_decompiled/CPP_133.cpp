```cpp
#include <vector>
#include <cmath>

int sum_squares(std::vector<float>& vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        float val1 = std::ceil(vec[i]);
        float val2 = std::ceil(vec[i]);
        sum += val1 * val2;
    }
    return sum;
}
```