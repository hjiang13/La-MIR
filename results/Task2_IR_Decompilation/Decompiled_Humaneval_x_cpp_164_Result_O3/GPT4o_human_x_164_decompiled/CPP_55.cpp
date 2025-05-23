```cpp
#include <iostream>

int f(int n) {
    int arr[1000] = {0};
    arr[1] = 1;

    if (n < 2) {
        return arr[n];
    }

    for (int i = 2; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << f(n) << std::endl;
    return 0;
}
```