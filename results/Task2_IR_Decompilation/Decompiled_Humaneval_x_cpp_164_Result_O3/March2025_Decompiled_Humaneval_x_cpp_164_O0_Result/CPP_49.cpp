```cpp
#include <iostream>

int modp(int a, int b) {
    int result = 1;
    int counter = 0;
    while (counter < a) {
        result = (result * 2) % b;
        counter++;
    }
    return result;
}

int main() {
    int a = 5; // Example input
    int b = 3; // Example input
    std::cout << modp(a, b) << std::endl;
    return 0;
}
```