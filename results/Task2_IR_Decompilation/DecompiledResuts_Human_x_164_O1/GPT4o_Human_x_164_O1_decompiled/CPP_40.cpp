```cpp
#include <vector>

extern "C" bool triples_sum_to_zero(std::vector<int> v) {
    int* data = v.data();
    size_t size = v.size();
    
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            for (size_t k = j + 1; k < size; ++k) {
                if (data[i] + data[j] + data[k] == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}
```