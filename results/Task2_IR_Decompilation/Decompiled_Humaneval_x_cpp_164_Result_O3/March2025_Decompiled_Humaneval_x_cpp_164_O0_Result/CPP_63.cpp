```cpp
#include <iostream>
#include <vector>

int fibfibi(int n) {
    std::vector<int> fib(100, 0);
    fib[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
    }
    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibfibi(n) << std::endl;
    return 0;
}
```