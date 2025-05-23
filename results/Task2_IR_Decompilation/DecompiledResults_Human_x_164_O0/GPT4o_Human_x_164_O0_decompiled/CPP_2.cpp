```cpp
#include <cmath>

float truncate_number(float input) {
    int truncated = static_cast<int>(input);
    return input - static_cast<float>(truncated);
}
```