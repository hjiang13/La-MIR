```cpp
#include <iostream>

int fib(int n) {
    int arr[100] = {0, 0, 1};
    
    if (n < 3) {
        return arr[n];
    }
    
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    return arr[n];
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Fibonacci of " << n << " is " << fib(n) << std::endl;
    return 0;
}
```