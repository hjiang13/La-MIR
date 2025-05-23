```cpp
#include <vector>
#include <algorithm>

int prod_signs(std::vector<int> v) {
    int result = -32768;
    for (size_t i = 0; i < v.size(); i++) {
        int num = std::abs(v[i]);
        result = result * ((v[i] < 0) ? -1 : 1) + num;
    }
    return result;
}
```