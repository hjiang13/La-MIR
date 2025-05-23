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
