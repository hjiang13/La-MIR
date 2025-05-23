```cpp
#include <vector>

void incr_list(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i] += 1;
    }
}
```