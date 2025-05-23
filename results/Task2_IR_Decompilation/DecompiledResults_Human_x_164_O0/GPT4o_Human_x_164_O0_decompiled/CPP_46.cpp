```cpp
#include <iostream>

int fib4i(int n) {
    int arr[100] = {0, 0, 2, 0};
    int i = 4;

    while (i <= n) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
        i++;
    }

    return arr[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib4i(n) << std::endl;
    return 0;
}
```