```cpp
#include <vector>
#include <algorithm>

extern "C" int sum_squares(std::vector<int>* vec) {
    int size = vec->size();
    if (size == 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        int value = (*vec)[i];
        if (i % 3 == 0) {
            sum += value * value;
        } else if ((i & 3) == 0) {
            sum += value * value * value;
        } else {
            sum += value;
        }
    }
    return sum;
}
```