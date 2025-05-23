```cpp
#include <cstdlib>

extern "C" int abs(int x) {
    return (x < 0) ? -x : x;
}

extern "C" int multiply(int a, int b) {
    int abs_a = abs(a);
    int abs_b = abs(b);
    return (abs_a % 10) * (abs_b % 10);
}
```