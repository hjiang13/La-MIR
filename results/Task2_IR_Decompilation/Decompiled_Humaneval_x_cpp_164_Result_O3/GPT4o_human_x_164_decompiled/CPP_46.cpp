```cpp
#include <iostream>

int fib4i(int n) {
    int array[100] = {0, 0, 2, 0};
    
    if (n < 4) {
        return n == 0 ? 0 : n == 1 ? 1 : n == 2 ? 2 : 2; 
    }
    
    int result = 0;
    for (int i = 4; i <= n; ++i) {
        if (i == 5) {
            array[i] = 2;
        } else {
            array[i] = array[i - 1] + array[i - 2] + array[i - 3];
        }
    }
    
    return array[n];
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "fib4i(" << n << ") = " << fib4i(n) << std::endl;
    return 0;
}
```