```c
#include <stdbool.h>

bool iscuber(int x) {
    int result = x;
    do {
        int square = result * result;
        int cube = square * result;
        if (cube < abs(x)) {
            result++;
        } else {
            return cube <= abs(x);
        }
    } while (true);
}

```