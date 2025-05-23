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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (change_base(8, 3) == "22");
    assert (change_base(9, 3) == "100");
    assert (change_base(234, 2) == "11101010");
    assert (change_base(16, 2) == "10000");
    assert (change_base(8, 2) == "1000");
    assert (change_base(7, 2) == "111");
    for (int x=2;x<8;x++)
        assert (change_base(x, x + 1) == to_string(x));
}
