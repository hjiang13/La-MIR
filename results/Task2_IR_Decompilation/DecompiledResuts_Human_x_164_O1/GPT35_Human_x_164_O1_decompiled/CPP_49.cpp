```c
#include <iostream>

int mod(int a, int b) {
    if (a > 0) {
        int res = 1;
        for (int i = 1; i < a; i++) {
            res = (res * 2) % b;
        }
        return res;
    }
    return 1;
}

int main() {
    int a = 5;
    int b = 3;
    int result = mod(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```