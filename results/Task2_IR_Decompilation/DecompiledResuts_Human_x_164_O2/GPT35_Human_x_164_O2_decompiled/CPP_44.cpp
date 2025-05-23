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
```