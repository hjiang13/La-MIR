```c
#include <vector>

bool below_threshold(std::vector<int>& vec, int threshold) {
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        if (vec[i] >= threshold) {
            return false;
        }
    }
    return true;
}
```