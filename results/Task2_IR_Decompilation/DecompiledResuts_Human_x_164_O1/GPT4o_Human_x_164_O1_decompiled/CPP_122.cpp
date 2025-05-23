```cpp
#include <vector>

int add_elements(std::vector<int> &vec, int n) {
    if (n > 0) {
        int sum = 0;
        for (size_t i = 0; i < n; ++i) {
            int val = vec[i];
            val += 99;
            if (val < 199) {
                sum += val;
            }
        }
        return sum;
    }
    return 0;
}
```