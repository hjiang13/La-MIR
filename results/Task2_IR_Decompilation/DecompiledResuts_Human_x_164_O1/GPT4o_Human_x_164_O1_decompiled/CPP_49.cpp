```cpp
#include <iostream>

int mod(int a, int b) {
    if (a > 0) {
        int count = 0;
        int remainder = 0;
        while (true) {
            if (count == a) {
                return 1;
            }
            remainder = (remainder << 1) % b;
            count++;
        }
    } else {
        return 1;
    }
}

int main() {
    int a = 10; // Example value
    int b = 3;  // Example value
    std::cout << mod(a, b) << std::endl;
    return 0;
}
```