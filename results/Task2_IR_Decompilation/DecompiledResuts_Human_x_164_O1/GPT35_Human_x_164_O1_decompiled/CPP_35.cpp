```c
#include <vector>
#include <algorithm>

float max_element(std::vector<float> vec) {
    float max_val = -10000;
    
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }
    
    return max_val;
}
```