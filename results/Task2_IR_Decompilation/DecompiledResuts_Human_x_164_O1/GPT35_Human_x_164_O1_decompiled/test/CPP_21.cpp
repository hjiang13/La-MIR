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
