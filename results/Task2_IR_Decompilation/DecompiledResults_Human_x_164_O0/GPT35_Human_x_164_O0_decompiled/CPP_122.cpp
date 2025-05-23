```cpp
#include <vector>

int add_elements(std::vector<int> &vec, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] >= -99 && vec[i] <= 99) {
            sum += vec[i];
        }
    }
    return sum;
}
```