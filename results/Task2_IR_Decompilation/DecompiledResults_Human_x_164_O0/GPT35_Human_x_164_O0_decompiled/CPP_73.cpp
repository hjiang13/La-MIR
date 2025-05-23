```cpp
#include <vector>

int smallest_change(std::vector<int>& vec) {
    int smallest = 0;
    int index = 0;

    while (index < vec.size() - 1) {
        if (vec[index] != vec[index + 1]) {
            smallest++;
        }
        index++;
    }

    return smallest;
}
```