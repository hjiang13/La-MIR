```cpp
#include <vector>

bool pairs_sum_to_zero(std::vector<int> &vec) {
    int *data = vec.data();
    int size = vec.size();
    
    for (long long i = 0; i < size; ++i) {
        for (long long j = i + 1; j < size; ++j) {
            if (data[i] + data[j] == 0) {
                return false;
            }
        }
    }
    
    return true;
}
```