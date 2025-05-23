```cpp
#include <iostream>

int choose_num(int a, int b) {
    if (b < a) {
        return -1;
    } else if (b % 2 == 1 && b == a) {
        return -1;
    } else {
        return b % 2 == 1 ? b + 1 : b;
    }
}

int main() {
    int a = 10;
    int b = 5;
    int result = choose_num(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```