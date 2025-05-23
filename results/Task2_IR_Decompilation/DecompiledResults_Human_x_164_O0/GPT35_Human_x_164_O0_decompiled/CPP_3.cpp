```cpp
#include <vector>

bool below_zero(std::vector<int>& vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        if (sum < 0) {
            return true;
        }
    }
    return false;
}
```