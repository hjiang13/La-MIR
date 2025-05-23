```c
#include <string>
#include <iostream>

std::string change_base(int num1, int num2) {
    std::allocator<char> alloc;
    std::__cxx11::basic_string<char> str("", alloc);
    
    if (num1 > 0) {
        int remainder = num1 % num2;
        std::__cxx11::basic_string<char> temp;
        temp = std::to_string(remainder);
        str = std::to_string(remainder) + str;
        
        int quotient = num1 / num2;
        num1 = quotient;
    }
    
    return str;
}

int main() {
    int num1 = 10;
    int num2 = 2;
    
    std::string result = change_base(num1, num2);
    
    std::cout << result << std::endl;
    
    return 0;
}
```