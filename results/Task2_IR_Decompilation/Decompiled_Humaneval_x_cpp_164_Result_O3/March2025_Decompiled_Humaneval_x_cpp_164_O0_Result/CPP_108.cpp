```cpp
#include <vector>
#include <cmath>

int count_nums(std::vector<int> vec) {
    int count = 0;
    int i = 0;
    while (i < vec.size()) {
        if (vec[i] > 0) {
            count++;
        } else {
            int sum = 0;
            int abs_val = std::abs(vec[i]);
            while (abs_val >= 10) {
                sum += abs_val % 10;
                abs_val /= 10;
            }
            sum -= abs_val;
            if (sum > 0) {
                count++;
            }
        }
        i++;
    }
    return count;
}
```