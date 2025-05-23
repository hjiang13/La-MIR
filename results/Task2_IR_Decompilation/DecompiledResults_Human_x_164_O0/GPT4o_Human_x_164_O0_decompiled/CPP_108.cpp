```cpp
#include <vector>
#include <cstdlib>

int count_nums(std::vector<int> &vec) {
    int count = 0;
    int index = 0;
    int remainder = 0;
    int abs_val = 0;

    for (index = 0; index < vec.size(); ++index) {
        if (vec[index] > 0) {
            count++;
        } else {
            abs_val = std::abs(vec[index]);
            if (abs_val >= 10) {
                remainder += abs_val % 10;
                count += remainder;
                remainder = abs_val / 10;
            } else {
                remainder = abs_val;
            }
        }
    }
    return count;
}
```