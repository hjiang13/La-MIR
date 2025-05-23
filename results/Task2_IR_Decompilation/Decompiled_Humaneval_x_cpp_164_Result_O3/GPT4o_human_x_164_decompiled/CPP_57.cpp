```cpp
#include <vector>

bool monotonic(std::vector<float> const& vec) {
    size_t size = vec.size();
    if (size <= 1) return true;

    int count = 0;
    for (size_t i = 1; i < size; ++i) {
        if (vec[i] > vec[i - 1]) {
            count++;
        } else if (vec[i] < vec[i - 1]) {
            count--;
        }
    }
    return count != 2;
}
```