```cpp
#include <vector>

bool pairs_sum_to_zero(std::vector<int>& vec) {
    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (vec[i] + vec[j] == 0) {
                return true;
            }
        }
    }
    return false;
}
```