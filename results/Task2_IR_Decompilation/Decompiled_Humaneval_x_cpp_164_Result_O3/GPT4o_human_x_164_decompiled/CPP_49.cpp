```cpp
#include <iostream>

int mod(int a, int b) {
    if (a <= 0) {
        return 1;
    }
    
    int temp = a & 3;
    if ((a - 1) < 3) {
        return (a & -4);
    }
    
    int result = 1;
    int count = 1;
    
    while (true) {
        if (temp == 0) {
            return result;
        }
        
        result = (result << 1) % b;
        temp--;
        
        if (temp == 0) {
            return result;
        }
    }
}

int main() {
    int a = 10; // Example input
    int b = 3;  // Example input
    std::cout << mod(a, b) << std::endl;
    return 0;
}
```