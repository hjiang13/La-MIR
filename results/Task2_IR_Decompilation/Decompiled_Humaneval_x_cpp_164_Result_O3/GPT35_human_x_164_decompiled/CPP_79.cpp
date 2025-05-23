```cpp
#include <string>
#include <cstdio>
#include <cstdarg>

void decimal_to_binary(std::string& s, int n) {
    if (n == 0) {
        s = "0";
        return;
    }
    
    std::string temp;
    if (n > 0) {
        temp = "1";
        n >>= 1;
    }
    
    while (n != 0) {
        temp = (n % 2 == 0 ? "0" : "1") + temp;
        n /= 2;
    }
    
    s = temp;
}

int main() {
    std::string result;
    int input = 42;
    
    decimal_to_binary(result, input);
    printf("Binary representation of %d is: %s\n", input, result.c_str());
    
    return 0;
}
```