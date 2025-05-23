```cpp
#include <cmath>

extern "C" bool any_int(float a, float b, float c) {
    if (std::round(a) != a) {
        return false;
    }
    if (std::round(b) != b) {
        return false;
    }
    if (std::round(c) != c) {
        return false;
    }
    if (a + b == c || a + c == b || b + c == a) {
        return true;
    }
    return false;
}
```