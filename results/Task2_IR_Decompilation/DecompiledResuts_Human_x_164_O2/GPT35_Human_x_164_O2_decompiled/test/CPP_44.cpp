```c++
#include <string>
#include <cstdio>

void change_base(std::__cxx11::basic_string& s, int num1, int num2) {
    std::__cxx11::basic_string s1;
    std::__cxx11::basic_string s2;
    
    int remainder = num1 % num2;
    int quotient = num1 / num2;
    
    char buffer[3];
    snprintf(buffer, sizeof(buffer), "%d", remainder);
    
    s2.append(buffer);
    
    if (quotient > 0) {
        change_base(s, quotient, num2);
    }
    
    s.append(s2);
}

int main() {
    std::__cxx11::basic_string s;
    int num1 = 123; // Input number
    int num2 = 2;   // Output base
    
    change_base(s, num1, num2);
    
    std::cout << s << std::endl;
    
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
