```cpp
#include <vector>

int add_elements(std::vector<int> &v, int n) {
    if (n > 0) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i] + 99;
            if (sum < 199) {
                v[i] = sum;
            } else {
                v[i] = 0;
            }
        }
        return sum;
    } else {
        return 0;
    }
}
```