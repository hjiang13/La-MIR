```cpp
#include <vector>

bool is_sorted(std::vector<int> &vec) {
    int *begin = vec.data();
    int *end = vec.data() + vec.size();

    if (end - begin > 1) {
        int prev = *begin;
        for (int *it = begin + 1; it != end; ++it) {
            if (*it < prev) {
                return false;
            }
            prev = *it;
        }
    }

    return true;
}
```