```cpp
#include <vector>

bool pairs_sum_to_zero(const std::vector<int>& vec) {
    auto start = vec.data();
    auto end = start + vec.size();
    
    if (end - start == 0) {
        return false;
    }

    int n = (end - start) / 4; // Assuming 4 bytes per int
    if (n == 0) {
        return false;
    }
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int val = start[i];
        if (val == 0) {
            return true;
        }
        count++;
    }

    return false;
}
```