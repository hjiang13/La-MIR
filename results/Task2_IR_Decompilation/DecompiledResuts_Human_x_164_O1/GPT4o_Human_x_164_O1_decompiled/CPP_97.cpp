```cpp
#include <cmath>

int multiply(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    return (b % 10) * (a % 10);
}
```