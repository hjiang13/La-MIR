```cpp
#include <vector>

bool will_it_fly(std::vector<int> &vec, int index) {
    int size = vec.size();
    int result = 0;
    
    for (int i = 0; i < size; ++i) {
        if (i == index) {
            continue;
        }
        result += vec[i];
    }
    
    return result > vec.size();
}
```