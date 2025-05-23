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