```c
#include <vector>
#include <cmath>

double double_the_difference(std::vector<float>& vec) {
    double result = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        float val1 = std::round(vec[i]);
        if (std::abs(val1 - std::round(vec[i + 1])) < 0.0001) {
            if (vec[i + 1] > 0) {
                if (static_cast<int>(std::round(vec[i])) % 2 == 1) {
                    result += static_cast<int>(std::round(vec[i])) * static_cast<int>(std::round(vec[i + 1]));
                }
            }
        }
    }
    return result;
}
```