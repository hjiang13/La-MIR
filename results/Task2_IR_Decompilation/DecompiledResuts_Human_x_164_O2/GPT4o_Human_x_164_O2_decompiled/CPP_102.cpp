```cpp
#include <iostream>

int choose_num(int a, int b) {
    if (b < a) {
        return -1;
    } else if (b == a) {
        if (b % 2 == 1) {
            return b + 1;
        }
    }
    return -1;
}

int main() {
    int a = 10;
    int b = 5;
    std::cout << choose_num(a, b) << std::endl;
    return 0;
}
```