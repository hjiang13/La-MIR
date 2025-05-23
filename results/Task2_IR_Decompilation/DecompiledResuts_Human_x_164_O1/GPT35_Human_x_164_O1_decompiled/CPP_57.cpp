```cpp
#include <vector>
#include <algorithm>

bool monotonic(std::vector<float> &vec) {
    float* data = vec.data();
    size_t size = vec.size();

    for (size_t i = 1; i < size; ++i) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }

    return true;
}
```