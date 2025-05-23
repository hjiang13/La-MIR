```cpp
#include <vector>
#include <algorithm>

float median(std::vector<float>& vec) {
    std::sort(vec.begin(), vec.end());
    size_t size = vec.size();
    if (size % 2 == 1) {
        return vec[size / 2];
    } else {
        return (vec[size / 2] + vec[size / 2 - 1]) * 0.5f;
    }
}
```