```cpp
#include <iostream>

int choose_num(int a, int b) {
    int result;
    if (a < b) {
        result = -1;
    } else {
        if (a == b) {
            if (a % 2 == 1) {
                result = -1;
            } else {
                result = a;
            }
        } else {
            if (a % 2 == 1) {
                result = a - 1;
            } else {
                result = a;
            }
        }
    }
    return result;
}

int main() {
    int a = 5;
    int b = 10;
    std::cout << choose_num(a, b) << std::endl;
    return 0;
}
```