```cpp
#include <vector>

int add_elements(std::vector<int>& vec, int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        int value = vec[i];
        if (value >= -99 && value <= 99) {
            total += value;
        }
    }
    return total;
}
```