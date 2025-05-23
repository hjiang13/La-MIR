```cpp
#include <vector>
#include <algorithm>

extern "C" int count_nums(std::vector<int>* vec) {
    int count = 0;
    if (vec->empty()) {
        return count;
    }

    int* data = vec->data();
    int size = vec->size();

    for (int i = 0; i < size; ++i) {
        int value = data[i];
        if (value > 0) {
            count += (value > 99) ? (value / 10) + (value % 10) : value;
        }
    }

    return count;
}
```