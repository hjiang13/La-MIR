```cpp
#include <vector>

bool below_zero(std::vector<int> &vec) {
    bool result = false;
    int sum = 0;
    int index = 0;
    
    while (index < vec.size()) {
        sum += vec[index];
        if (sum < 0) {
            result = true;
            break;
        }
        index++;
    }
    
    return result;
}
```