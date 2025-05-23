```cpp
#include <vector>

bool move_one_ball(std::vector<int> &v) {
    int *data = v.data();
    int size = v.size();
    
    if (size == 0) {
        return false;
    }
    
    int count = 0;
    
    for (int i = 0; i < size; ++i) {
        if (data[i] > 0) {
            count++;
        }
    }
    
    return count < 2;
}
```