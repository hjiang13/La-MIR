```cpp
#include <vector>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    float temp;
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        temp = input[i] * static_cast<float>(i);
        result.push_back(temp);
    }
}
```