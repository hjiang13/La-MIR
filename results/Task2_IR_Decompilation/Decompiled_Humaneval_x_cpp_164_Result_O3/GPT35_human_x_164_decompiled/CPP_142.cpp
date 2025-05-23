```cpp
#include <vector>
#include <algorithm>

int sum_squares(std::vector<int> vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i] * vec[i];
    }
    return sum;
}
```