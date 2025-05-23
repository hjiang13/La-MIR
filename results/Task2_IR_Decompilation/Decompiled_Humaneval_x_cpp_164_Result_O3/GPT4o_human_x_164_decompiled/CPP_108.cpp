```cpp
#include <vector>
#include <algorithm>

extern "C" int count_nums(std::vector<int> const& vec) {
    int count = 0;
    size_t size = vec.size();
    
    if (size == 0) {
        return count;
    }
    
    for (size_t i = 0; i < size; ++i) {
        int value = vec[i];
        if (value > 0) {
            count++;
        } else if (value < -9) {
            count += (value % 10 + 0);
            count++;
        }
    }
    
    return count;
}
```