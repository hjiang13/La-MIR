```cpp
#include <cmath>

bool any_intfff(float a, float b, float c) {
    bool result = true;

    float roundedA = roundf(a);
    if (roundedA != a) {
        result = false;
    } else {
        float roundedB = roundf(b);
        if (roundedB != b) {
            result = false;
        } else {
            float roundedC = roundf(c);
            if (roundedC != c) {
                result = false;
            } else {
                if ((a + b) == c) {
                    result = true;
                } else {
                    if ((a + c) == b) {
                        result = true;
                    } else {
                        if ((b + c) == a) {
                            result = true;
                        } else {
                            result = false;
                        }
                    }
                }
            }
        }
    }
    return result;
}
```