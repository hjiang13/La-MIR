```c
#include <iostream>

int add(int a, int b) {
    int result;
    result = a + b;
    return result;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    
    int sum = add(num1, num2);
    
    std::cout << "Sum: " << sum << std::endl;
    
    return 0;
}
```