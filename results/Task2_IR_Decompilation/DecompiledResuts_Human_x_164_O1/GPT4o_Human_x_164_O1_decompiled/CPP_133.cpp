```cpp
#include <vector>
#include <cmath>

extern "C" int sum_squares(std::vector<float> const& vec) {
    float* data = vec.data();
    if (data == nullptr) {
        return 0;
    }
    
    size_t size = vec.size();
    int result = 0;

    for (size_t i = 0; i < size; ++i) {
        float value = std::ceil(data[i]);
        result += static_cast<int>(value * value) + static_cast<int>(i);
    }

    return result;
}
```