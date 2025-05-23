```c
#include <iostream>

int add(int a, int b) {
    return b + a;
}

int main() {
    int result = add(5, 10);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```