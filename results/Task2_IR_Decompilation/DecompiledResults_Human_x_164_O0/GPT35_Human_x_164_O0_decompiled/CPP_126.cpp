```c
#include <vector>

bool is_sorted(std::vector<int>& vec) {
    bool result = true;
    int index = 1;
    
    while (index < vec.size()) {
        if (vec[index] < vec[index - 1]) {
            result = false;
            break;
        }
        
        index++;
    }
    
    return result;
}
```