```cpp
#include <vector>
#include <stdexcept>

void get_positive(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        float value = input[i];
        if (value > 0.0f) {
            result.push_back(value);
        }
    }
}
```