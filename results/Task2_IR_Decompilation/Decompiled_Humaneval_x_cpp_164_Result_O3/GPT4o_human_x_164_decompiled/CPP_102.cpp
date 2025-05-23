```cpp
#include <iostream>

int choose_num(int a, int b) {
    if (b < a) {
        if (b == a) {
            return -1;
        }
        int remainder = b % 2;
        if (remainder == 1) {
            return b + 1;
        }
        return -1;
    }
    return -1;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << choose_num(a, b) << std::endl;
    return 0;
}
```