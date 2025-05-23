```cpp
#include <cmath>

extern "C" int abs(int x) {
    return (x < 0) ? -x : x;
}

extern "C" bool iscube(int n) {
    int abs_n = abs(n);
    int x = 0;
    while (true) {
        int cube = x * x * x;
        if (cube >= abs_n) {
            break;
        }
        x++;
    }
    return (x * x * x) == abs_n;
}
```