```cpp
#include <vector>

bool monotonic(std::vector<float>& vec) {
    int size = vec.size();
    int increasing = 0;
    int decreasing = 0;

    for (int i = 1; i < size; i++) {
        if (vec[i] > vec[i - 1]) {
            increasing = 1;
        } else if (vec[i] < vec[i - 1]) {
            decreasing = 1;
        }
    }

    return !(increasing && decreasing);
}
```