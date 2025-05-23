```cpp
#include <vector>

float max_element(std::vector<float>& vec) {
    float max_val = -1.0e+04;
    int index = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        if (max_val < vec[i]) {
            max_val = vec[i];
        }
    }
    
    return max_val;
}
```