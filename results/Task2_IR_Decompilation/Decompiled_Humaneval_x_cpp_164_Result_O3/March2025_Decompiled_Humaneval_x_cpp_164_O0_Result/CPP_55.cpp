```cpp
#include <iostream>

int fib(int n) {
    int fibArray[1000];
    fibArray[0] = 0;
    fibArray[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
    return fibArray[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib(n) << std::endl;
    return 0;
}
```