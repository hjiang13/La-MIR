```cpp
#include <vector>
#include <algorithm>

int next_smallest(std::vector<int>& vec) {
    int* begin = vec.data();
    int* end = begin + vec.size();
    std::sort(begin, end);
    
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] != vec[vec.size() - 1 - i]) {
            return vec[i];
        }
    }
    return -1;
}
```