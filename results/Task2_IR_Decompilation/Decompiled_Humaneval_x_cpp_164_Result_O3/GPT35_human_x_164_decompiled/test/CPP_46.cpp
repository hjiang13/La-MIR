Here is the decompiled C++ source code from the given LLVM IR code:

```cpp
#include <iostream>

int fib(int n) {
    int arr[100] = {0, 0, 2, 0};
    
    if (n < 4) {
        return arr[n];
    }
    
    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 3] + arr[i - 4];
    }
    
    return arr[n];
}

int main() {
    int n = 10; // Change the value of n as needed
    std::cout << "Fibonacci of " << n << " is: " << fib(n) << std::endl;
    
    return 0;
}
```

You can run this code to calculate the Fibonacci number for a given input `n`. Just replace the value of `n` in the `main` function with the desired input.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
