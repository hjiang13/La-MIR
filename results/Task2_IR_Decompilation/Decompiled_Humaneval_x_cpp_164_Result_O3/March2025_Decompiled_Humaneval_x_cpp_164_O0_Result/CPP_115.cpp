```cpp
#include <vector>
#include <algorithm>

int max_fill(std::vector<std::vector<int>>& vec, int divisor) {
    int result = 0;
    int outer_index = 0;

    while (outer_index < vec.size()) {
        int sum = 0;
        int inner_index = 0;

        while (inner_index < vec[outer_index].size()) {
            sum += vec[outer_index][inner_index];
            ++inner_index;
        }

        if (sum > 0) {
            result += (sum - 1) / divisor + 1;
        }

        ++outer_index;
    }

    return result;
}
```