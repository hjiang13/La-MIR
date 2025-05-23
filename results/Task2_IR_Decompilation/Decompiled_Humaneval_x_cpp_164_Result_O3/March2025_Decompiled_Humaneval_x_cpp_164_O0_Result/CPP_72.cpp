```cpp
#include <vector>

bool will_it_fly(std::vector<int> vec, int threshold) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] != vec[vec.size() - 1 - i]) {
            return false;
        }
        sum += vec[i];
    }
    return sum <= threshold;
}
```