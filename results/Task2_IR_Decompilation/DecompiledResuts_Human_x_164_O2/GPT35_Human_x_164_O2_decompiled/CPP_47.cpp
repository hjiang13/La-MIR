```cpp
#include <vector>
#include <algorithm>

float median(std::vector<float> vec) {
    if (vec.size() == 0) {
        return 0.0f;
    }

    std::sort(vec.begin(), vec.end());
    int size = vec.size();

    if (size % 2 == 0) {
        return (vec[size / 2 - 1] + vec[size / 2]) * 0.5f;
    } else {
        return vec[size / 2];
    }
}
```