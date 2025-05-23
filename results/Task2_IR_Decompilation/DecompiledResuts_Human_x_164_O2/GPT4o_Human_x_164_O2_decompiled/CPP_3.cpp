```cpp
#include <vector>

bool below_zero(std::vector<int> &vec) {
    int *begin = vec.data();
    int *end = begin + vec.size();
    int count = 0;

    for (int *ptr = begin; ptr < end; ++ptr) {
        if (*ptr < 0) {
            count++;
        }
    }

    return count > 0;
}
```