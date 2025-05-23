```cpp
#include <vector>

bool monotonic(const std::vector<float>& vec) {
    bool increasing = false;
    bool decreasing = false;

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > vec[i - 1]) {
            increasing = true;
        }
        if (vec[i] < vec[i - 1]) {
            decreasing = true;
        }
    }

    return !(increasing && decreasing);
}
```