```cpp
#include <vector>
#include <cstdlib>
#include <algorithm>

int prod_signs(std::vector<int> &vec) {
    int count = 0;
    int product = 1;
    size_t size = vec.size();

    if (size == 0) return 0;

    for (size_t i = 0; i < size; ++i) {
        int value = std::abs(vec[i]);
        count += (value != 0) ? 1 : 0;

        if (vec[i] < 0) {
            product *= -1;
        }
    }

    return (count == 0) ? 0 : product;
}
```