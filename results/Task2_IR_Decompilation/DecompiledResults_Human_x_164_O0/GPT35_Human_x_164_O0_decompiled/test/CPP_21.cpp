Here is the decompiled C++ source code from the provided LLVM IR code:

```cpp
#include <vector>

void rescale_to_unit(std::vector<float>& result, std::vector<float>& input) {
    float max_val = 1.000000e+05;
    float min_val = -1.000000e+05;
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i] < max_val) {
            max_val = input[i];
        }
        if (input[i] > min_val) {
            min_val = input[i];
        }
    }
    
    for (int i = 0; i < input.size(); i++) {
        result[i] = (input[i] - max_val) / (min_val - max_val);
    }
}

int main() {
    std::vector<float> input = {10.0, 20.0, 30.0};
    std::vector<float> result(input.size());
    
    rescale_to_unit(result, input);
    
    return 0;
}
```

The provided LLVM IR code has been decompiled into a C++ source code format that can be run directly.
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
