```cpp
#include <iostream>
#include <vector>

int fib4(int n) {
    std::vector<int> fib(100, 0);
    fib[2] = 2;

    for (int i = 4; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3] + fib[i - 4];
    }

    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib4(n) << std::endl;
    return 0;
}
```