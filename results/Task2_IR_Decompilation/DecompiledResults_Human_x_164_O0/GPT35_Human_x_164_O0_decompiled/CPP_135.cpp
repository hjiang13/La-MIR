```cpp
#include <vector>

int can_arrange(std::vector<int> *arr) {
    int max_idx = -1;
    int idx = 0;
    
    while (idx < arr->size()) {
        int val = (*arr)[idx];
        
        if (val <= idx) {
            max_idx = idx;
        }
        
        idx++;
    }
    
    return max_idx;
}
```