```cpp
#include <vector>

bool will_it_fly(std::vector<int>& vec, int val) {
    int index = 0;
    int sum = 0;

    while (index < vec.size()) {
        int current_val = vec[index];
        int next_val = vec[vec.size() - 1 - index];

        if (current_val != next_val) {
            return false;
        } else {
            sum += current_val;
        }

        index++;
    }

    return sum > val;
}
```