```cpp
#include <vector>

bool triples_sum_to_zero(std::vector<int>& vec) {
    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            for (int k = j + 1; k < size; ++k) {
                if (vec[i] + vec[j] + vec[k] == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}
```