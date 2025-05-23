```cpp
#include <vector>

int add(std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] % 2 == 0) {
            sum += vec[i];
        }
    }
    return sum;
}
```