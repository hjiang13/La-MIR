```cpp
#include <vector>

int sum_squares(std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i % 3 == 0) {
            sum += vec[i] * vec[i];
        } else if (i % 4 == 0) {
            sum += vec[i] * vec[i] * vec[i];
        } else {
            sum += vec[i];
        }
    }
    return sum;
}
```