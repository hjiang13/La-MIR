```cpp
#include <vector>

int smallest_change(std::vector<int> &vec) {
    int count = 0;
    int index = 0;
    while (true) {
        if (index >= vec.size() - 1) {
            break;
        }
        int value1 = vec[index];
        int value2 = vec[index + 1];
        if (value1 != value2) {
            count++;
        }
        index++;
    }
    return count;
}
```