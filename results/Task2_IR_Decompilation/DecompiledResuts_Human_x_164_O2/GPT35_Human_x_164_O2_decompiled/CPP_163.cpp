```cpp
#include <vector>

void generate_integers(std::vector<int>& vec, int start, int end) {
    int actual_start = (end < start) ? start : end;
    int actual_end = (end < start) ? end : start;
    
    vec.clear();
    
    for (int i = actual_start; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        
        if (vec.size() == vec.capacity()) {
            throw std::length_error("vector::_M_realloc_insert");
        }
        
        vec.push_back(i);
    }
}
```