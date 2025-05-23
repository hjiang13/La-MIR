```cpp
#include <vector>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    std::vector<float> temp(2);
    
    if (input.size() < 2) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }
    
    for (size_t i = 0; i < input.size() - 1; ++i) {
        float diff = std::fabs(input[i] - input[i + 1]);
        float current_diff = std::fabs(temp[0] - temp[1]);
        
        if (diff < current_diff) {
            temp[0] = input[i];
            temp[1] = input[i + 1];
        }
    }
    
    result.assign(temp.begin(), temp.end());
}
```