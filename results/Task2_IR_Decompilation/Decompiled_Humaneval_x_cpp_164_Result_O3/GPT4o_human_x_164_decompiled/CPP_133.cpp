```cpp
#include <vector>
#include <cmath>
#include <cstdint>

int sum_squares(std::vector<float> const& vec) {
    if (vec.empty()) return 0;
    
    int32_t result = 0;
    for (size_t i = 0; i < vec.size(); i += 2) {
        float x = std::ceil(vec[i]);
        result += static_cast<int32_t>(x * x);

        if (i + 1 < vec.size()) {
            float y = std::ceil(vec[i + 1]);
            result += static_cast<int32_t>(y * y);
        }
    }
    return result;
}
```