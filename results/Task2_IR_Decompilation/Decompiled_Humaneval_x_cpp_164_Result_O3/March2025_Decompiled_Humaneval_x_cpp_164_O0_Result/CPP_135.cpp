```cpp
#include <vector>

int can_arrange(std::vector<int> vec) {
    int result = -1;
    int index = 0;
    while (index < vec.size()) {
        if (vec[index] <= index) {
            result = index;
        }
        index++;
    }
    return result;
}
```