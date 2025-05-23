```cpp
#include <iostream>

int choose_num(int a, int b) {
    if (b < a) {
        if (b == a) {
            return -1;
        }
        int mod = b % 2;
        if (mod == 1) {
            return -1;
        }
        return b + mod;
    }
    return -1;
}

int main() {
    int a = 10; // Example input
    int b = 5;  // Example input
    std::cout << choose_num(a, b) << std::endl;
    return 0;
}
```