```cpp
#include <vector>
#include <algorithm>

int prod_signs(std::vector<int> &vec) {
    int result = 0;
    int sign = 1;
    int sum = 0;
    
    for (size_t i = 0; i < vec.size(); i += 2) {
        int val1 = std::abs(vec[i]);
        int val2 = std::abs(vec[i + 1]);
        
        sum += val1 + sign;
        sum += val2 + sign;
        
        sign = (vec[i] < 0) ? -sign : sign;
        sign = (vec[i + 1] < 0) ? -sign : sign;
        
        result = sum * sign;
    }
    
    return result;
}
```