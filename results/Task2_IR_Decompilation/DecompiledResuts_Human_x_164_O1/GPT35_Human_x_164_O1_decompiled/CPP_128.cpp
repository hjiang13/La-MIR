```cpp
#include <vector>
#include <algorithm>

int prod_signs(std::vector<int> &v) {
    int result = 1;
    for (int i = 0; i < v.size(); i++) {
        int val = std::abs(v[i]);
        result += val;
        if (v[i] == 0) {
            result = 0;
        } else {
            result += (v[i] < 0) ? -1 : 1;
        }
    }
    return result;
}
```