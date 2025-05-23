```cpp
#include <vector>
#include <algorithm>

float median(std::vector<float>& vec) {
    float result;
    std::sort(vec.begin(), vec.end());
    size_t size = vec.size();
    if (size % 2 == 1) {
        result = vec[size / 2];
    } else {
        result = (vec[size / 2 - 1] + vec[size / 2]) / 2.0f;
    }
    return result;
}
```