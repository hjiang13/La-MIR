```cpp
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdint>

void rescale_to_unit(std::vector<float>& output, const std::vector<float>& input) {
    float* input_data = input.data();
    float* output_data = output.data();
    size_t size = input.size();

    if (size == 0) {
        std::memset(output_data, 0, sizeof(float) * 3);
        return;
    }

    float min_val = 1e5;
    float max_val = -1e5;

    for (size_t i = 0; i < size; ++i) {
        min_val = std::min(min_val, input_data[i]);
        max_val = std::max(max_val, input_data[i]);
    }

    if (max_val - min_val == 0) {
        std::memset(output_data, 0, sizeof(float) * 3);
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        output_data[i] = (input_data[i] - min_val) / (max_val - min_val);
    }
}
```