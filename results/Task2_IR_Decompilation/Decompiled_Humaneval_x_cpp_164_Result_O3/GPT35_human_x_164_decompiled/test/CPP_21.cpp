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

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(rescale_to_unit({2.0, 49.9}) , {0.0, 1.0}));
     assert (issame(rescale_to_unit({100.0, 49.9}) ,{1.0, 0.0})); 
     assert (issame(rescale_to_unit({1.0, 2.0, 3.0, 4.0, 5.0}) , {0.0, 0.25, 0.5, 0.75, 1.0}));
    assert (issame(rescale_to_unit({2.0, 1.0, 5.0, 3.0, 4.0}) , {0.25, 0.0, 1.0, 0.5, 0.75}));
     assert (issame(rescale_to_unit({12.0, 11.0, 15.0, 13.0, 14.0}) ,{0.25, 0.0, 1.0, 0.5, 0.75}));
}
