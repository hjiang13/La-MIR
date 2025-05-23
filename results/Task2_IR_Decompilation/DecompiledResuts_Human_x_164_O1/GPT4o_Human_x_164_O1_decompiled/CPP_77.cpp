```cpp
#include <cmath>

extern "C" {
    int abs(int x) {
        return (x < 0) ? -x : x;
    }
}

bool iscuberi(int n) {
    int cube = abs(n);
    int x = 0;

    while (true) {
        int y = x * x * x;
        if (y >= cube) {
            return y == cube;
        }
        x++;
    }
}
```