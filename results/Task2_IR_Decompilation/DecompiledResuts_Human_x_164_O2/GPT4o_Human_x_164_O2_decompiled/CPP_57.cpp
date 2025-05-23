```cpp
#include <vector>

bool monotonic(std::vector<float> const& vec) {
    if (vec.size() < 2) {
        return true;
    }
    int count = 0;
    float prev = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > prev) {
            count++;
        } else if (vec[i] < prev) {
            count++;
        }
        prev = vec[i];
    }
    return count != 2;
}
```