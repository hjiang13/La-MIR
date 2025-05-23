```cpp
#include <vector>

int smallest_change(std::vector<int>& vec) {
    int count = 0;
    int i = 0;
    while (i < vec.size() - 1) {
        if (vec[i] != vec[vec.size() - 1 - i]) {
            count++;
        }
        i++;
    }
    return count;
}
```