```cpp
#include <cmath>

float truncate_number(float x) {
    int32_t intPart = static_cast<int32_t>(x);
    float truncated = x - static_cast<float>(intPart);
    return truncated;
}
```