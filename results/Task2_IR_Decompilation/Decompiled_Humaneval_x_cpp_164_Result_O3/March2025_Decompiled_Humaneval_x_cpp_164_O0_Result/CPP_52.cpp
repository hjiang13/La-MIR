```cpp
#include <vector>

bool below_threshold(const std::vector<int>& vec, int threshold) {
    for (int value : vec) {
        if (value < threshold) {
            return false;
        }
    }
    return true;
}
```