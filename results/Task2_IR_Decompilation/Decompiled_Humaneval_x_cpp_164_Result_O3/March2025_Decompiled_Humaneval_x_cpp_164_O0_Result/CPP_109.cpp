```cpp
#include <vector>

bool move_one_ball(std::vector<int>& vec) {
    if (vec.size() == 0) {
        return true;
    }

    int count = 0;
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            ++count;
        }
    }

    if (vec.back() > vec.front()) {
        ++count;
    }

    return count < 2;
}
```