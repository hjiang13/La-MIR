```cpp
#include <vector>

int can_arrange(std::vector<int> &vec) {
    int index = 0;
    int result = -1;
    
    while (index < vec.size()) {
        int currentValue = vec[index];
        if (currentValue <= index) {
            result = index;
        }
        index++;
    }
    
    return result;
}
```