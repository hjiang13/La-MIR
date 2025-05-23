```cpp
#include <cmath>

bool iscuber(int n) {
    int i = 0;
    while (true) {
        int cube = i * i * i;
        if (cube == std::abs(n)) {
            return true;
        }
        if (cube > std::abs(n)) {
            return false;
        }
        i++;
    }
}
```