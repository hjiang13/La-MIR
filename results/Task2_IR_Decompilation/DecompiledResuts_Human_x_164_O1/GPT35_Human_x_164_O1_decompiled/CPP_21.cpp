```c
#include <vector>

void rescale_to_unit(std::vector<float>& output, std::vector<float>& input) {
    float* input_begin = &input[0];
    float* input_end = &input[0];
    float* output_begin = &output[0];
    float* output_end = &output[0];
    
    size_t size = input_end - input_begin;
    size = size > 1 ? size : 1;
    
    float min_val = -100000.0f;
    float max_val = 100000.0f;
    
    for (size_t i = 0; i < size; i++) {
        float val = input_begin[i];
        if (val < max_val) {
            max_val = val;
        }
        if (val > min_val) {
            min_val = val;
        }
    }
    
    for (size_t i = 0; i < size; i++) {
        float val = input_begin[i];
        float scaled_val = (val - max_val) / (min_val - max_val);
        output_begin[i] = scaled_val;
    }
}
```