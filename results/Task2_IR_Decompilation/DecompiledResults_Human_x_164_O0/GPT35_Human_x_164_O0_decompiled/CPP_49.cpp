```cpp
#include <iostream>

int mod(int a, int b) {
    int var0;
    int var1;
    int var2;
    int var3;
    
    var0 = a;
    var1 = b;
    var2 = 1;
    var3 = 0;
    
    while (var3 < var0) {
        var2 = (var2 * 2) % var1;
        var3++;
    }
    
    return var2;
}

int main() {
    int a = 10;
    int b = 3;
    int result = mod(a, b);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
```