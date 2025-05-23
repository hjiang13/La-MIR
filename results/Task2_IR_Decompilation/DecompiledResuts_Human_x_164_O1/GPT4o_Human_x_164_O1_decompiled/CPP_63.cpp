```cpp
#include <iostream>

int fib(int n) {
    int arr[100] = {0};
    arr[1] = 0;
    arr[2] = 1;

    if (n < 3) {
        return arr[n];
    }

    for (int i = 3; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib(n) << std::endl;
    return 0;
}
```