```cpp
#include <vector>

int smallest_change(std::vector<int> const &vec) {
    auto begin = vec.data();
    auto end = begin + vec.size();
    
    if (begin == end) {
        return 0;
    }

    int count = 0;
    for (auto it1 = begin; it1 < end; ++it1) {
        for (auto it2 = it1 + 1; it2 < end; ++it2) {
            if (*it1 != *it2) {
                count++;
            }
        }
    }
    
    return count;
}
```