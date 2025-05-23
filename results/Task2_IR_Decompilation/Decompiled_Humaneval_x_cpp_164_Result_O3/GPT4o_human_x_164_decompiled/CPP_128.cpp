```cpp
#include <vector>
#include <cstdlib>
#include <algorithm>

int prod_signs(std::vector<int> &vec) {
    int count = 0;
    int negative_count = 0;
    int zero_count = 0;

    for (size_t i = 0; i < vec.size(); i++) {
        int value = std::abs(vec[i]);
        if (vec[i] < 0) {
            negative_count++;
        }
        if (value == 0) {
            zero_count++;
        }
        count += value;
    }

    if (zero_count > 0) {
        return 0;
    }
    
    if (negative_count % 2 == 0) {
        return count;
    } else {
        return -count;
    }
}
```