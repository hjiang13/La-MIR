```cpp
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdint>
#include <limits>

void rescale_to_unit(std::vector<float>& output, const std::vector<float>& input) {
    const float minValue = -1.0e+5;
    const float maxValue = 1.0e+5;

    float currentMin = maxValue;
    float currentMax = minValue;

    for (size_t i = 0; i < input.size(); ++i) {
        currentMin = std::min(currentMin, input[i]);
        currentMax = std::max(currentMax, input[i]);
    }

    output.resize(3);
    output[0] = currentMin;
    output[1] = currentMax;

    for (size_t i = 0; i < input.size(); ++i) {
        float scaledValue = (input[i] - currentMin) / (currentMax - currentMin);
        output.push_back(scaledValue);
    }
}
```