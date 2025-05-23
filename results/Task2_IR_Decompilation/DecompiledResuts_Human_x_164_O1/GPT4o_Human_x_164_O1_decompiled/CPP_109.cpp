```cpp
#include <vector>

bool move_one_ball(std::vector<int> &vec) {
    int *data = vec.data();
    int *end = data + vec.size();
    int size = end - data;
    
    if (size == 0) return true;
    
    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (data[i] > data[i + 1]) {
            count++;
        }
    }
    
    return count < 2;
}
```