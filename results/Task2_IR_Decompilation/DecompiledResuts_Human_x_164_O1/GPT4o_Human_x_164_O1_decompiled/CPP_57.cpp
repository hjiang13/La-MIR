```cpp
#include <vector>

bool monotonic(std::vector<float> &vec) {
    size_t size = vec.size();
    if (size < 2) return true;

    int count = 0;
    for (size_t i = 1; i < size; ++i) {
        if (vec[i] > vec[i - 1]) {
            count |= 1;
        } else if (vec[i] < vec[i - 1]) {
            count |= 2;
        }
    }
    return count != 3;
}
```