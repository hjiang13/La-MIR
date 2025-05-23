```cpp
#include <iostream>

int sum_to_n(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << sum_to_n(n) << std::endl;
    return 0;
}
```