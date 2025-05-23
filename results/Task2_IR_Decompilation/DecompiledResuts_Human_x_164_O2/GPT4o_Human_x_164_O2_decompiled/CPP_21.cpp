```cpp
#include <vector>
#include <algorithm>
#include <cstring>

void rescale_to_unit(std::vector<float>& output, std::vector<float>& input) {
    float* out_data = output.data();
    float* in_data = input.data();
    size_t input_size = input.size();
    float min_val = 1e5;
    float max_val = -1e5;

    for (size_t i = 0; i < input_size; ++i) {
        float value = in_data[i];
        if (value < min_val) min_val = value;
        if (value > max_val) max_val = value;
    }

    for (size_t i = 0; i < input_size; ++i) {
        out_data[i] = (in_data[i] - min_val) / (max_val - min_val);
    }
}
```