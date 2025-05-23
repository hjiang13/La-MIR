```cpp
#include <cstdlib>

int multiply(int a, int b) {
    int abs_a = std::abs(a);
    int abs_b = std::abs(b);
    int mod_a = abs_a % 10;
    int mod_b = abs_b % 10;
    return mod_a * mod_b;
}
```