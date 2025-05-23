```cpp
#include <vector>
#include <cmath>

int double_the_difference(std::vector<float> &v) {
    float *begin = &v[0];
    float *end = &v[0];
    
    long diff = begin - end;
    if (diff == 0) {
        return 0;
    }
    
    long max_diff = std::max(diff >> 2, 1);
    
    long sum = 0;
    for (int i = 0; i < max_diff; i++) {
        float val = *(end + i);
        float rounded_val = std::round(val);
        double diff = val - rounded_val;
        
        bool condition = (diff < 0.0001) && (val > 0.0);
        
        if (condition) {
            int rounded_val_int = static_cast<int>(rounded_val);
            if (rounded_val_int % 2 == 1) {
                sum += rounded_val_int * rounded_val_int;
            }
        }
    }
    
    return sum;
}
```