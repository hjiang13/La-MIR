```cpp
#include <vector>

bool triples_sum_to_zero(std::vector<int> vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            for (size_t k = j + 1; k < vec.size(); ++k) {
                if (vec[i] + vec[j] + vec[k] == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}
```