```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    size_t input_size = input.size();
    if (input_size <= 1) return;

    result.resize(input_size);
    float scale = static_cast<float>(input_size - 1);
    
    for (size_t i = 0; i < input_size - 1; ++i) {
        result[i] = input[i] * (i / scale);
    }

    result[input_size - 1] = input[input_size - 1];
}
```