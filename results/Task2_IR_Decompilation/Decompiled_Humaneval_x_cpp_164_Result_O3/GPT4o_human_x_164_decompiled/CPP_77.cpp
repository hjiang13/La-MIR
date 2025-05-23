```cpp
#include <cmath>

bool iscuberi(int x) {
    int abs_x = std::abs(x);
    int y = 0;

    while (true) {
        int cube = y * y * y;
        if (cube >= abs_x) {
            break;
        }
        y++;
    }

    return (y * y * y) <= abs_x;
}
```