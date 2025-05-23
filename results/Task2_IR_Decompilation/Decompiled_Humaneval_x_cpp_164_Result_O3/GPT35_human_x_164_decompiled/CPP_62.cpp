```cpp
#include <vector>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    
    if (input.size() > 1) {
        for (size_t i = 0; i < input.size(); ++i) {
            float val = input[i] * static_cast<float>(i);
            result.push_back(val);
        }
    }
}
```