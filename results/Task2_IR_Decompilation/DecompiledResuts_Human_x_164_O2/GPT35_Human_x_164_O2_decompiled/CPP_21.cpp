```c
#include <vector>
#include <algorithm>

void rescale_to_unit(std::vector<float>& result, std::vector<float>& input) {
    float* input_begin = &input.front();
    float* input_end = input_begin + input.size();
    
    float min_val = *std::min_element(input_begin, input_end);
    float max_val = *std::max_element(input_begin, input_end);
    
    if (max_val == min_val) {
        return;
    }
    
    for (size_t i = 0; i < input.size(); ++i) {
        result[i] = (input[i] - min_val) / (max_val - min_val);
    }
    
    input.clear();
}
```