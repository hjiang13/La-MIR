```cpp
#include <vector>
#include <algorithm>
#include <cstdlib>

int prod_signs(std::vector<int>& vec) {
    int countNeg = 0;
    int countZero = 0;
    size_t size = vec.size();

    if (size == 0) return 0;

    for (size_t i = 0; i < size; ++i) {
        if (vec[i] == 0) {
            countZero++;
        } else if (vec[i] < 0) {
            countNeg++;
        }
    }

    if (countZero > 0) return 0;
    
    return (countNeg % 2 == 0) ? 1 : -1;
}
```