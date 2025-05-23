```cpp
#include <vector>

struct _Vector_impl_data {
    float* first;
    float* last;
    float* end_of_storage;
};

struct _Vector_impl {
    _Vector_impl_data _M_data;
};

struct _Vector_base {
    _Vector_impl _M_impl;
};

void rescale_to_unit(std::vector<float>& rescaled, std::vector<float>& original) {
    float* rescaled_first = original.data();
    float* rescaled_last = original.data();
    float* original_first = original.data();
    float* original_last = original.data();
    
    size_t num_elements = (original_last - original_first) / sizeof(float);
    
    if (num_elements == 0) {
        return;
    }
    
    size_t num_iterations = (num_elements > 1) ? num_elements : 1;
    
    for (size_t i = 0; i < num_iterations; ++i) {
        float min_value = -100000.0f;
        float max_value = 100000.0f;
        
        float current_value = original[i];
        float rescaled_value;
        
        if (current_value < min_value) {
            rescaled_value = current_value;
        } else if (current_value > max_value) {
            rescaled_value = max_value;
        } else {
            rescaled_value = (current_value - min_value) / (max_value - min_value);
        }
        
        rescaled[i] = rescaled_value;
    }
}
```