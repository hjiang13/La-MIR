```cpp
#include <iostream>

int x_or_y(int a, int b, int c) {
    int result;
    bool flag = true;

    if (a < 2) {
        flag = false;
    }

    int temp = 2;
    while (temp * temp <= a) {
        if (a % temp == 0) {
            flag = false;
        }
        temp++;
    }

    if (flag) {
        result = b;
    } else {
        result = c;
    }

    return result;
}

int main() {
    int a = 5, b = 10, c = 20;
    std::cout << x_or_y(a, b, c) << std::endl;
    return 0;
}
```