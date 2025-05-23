```c
#include <iostream>

int x_or_y(int x, int y, int i) {
    if (x > 1) {
        if (x < 4) {
            if ((x % i) == 0) {
                return y;
            } else {
                return x;
            }
        }
    }

    return 2;
}

int main() {
    int result = x_or_y(5, 6, 3);
    std::cout << result << std::endl;
    return 0;
}
```