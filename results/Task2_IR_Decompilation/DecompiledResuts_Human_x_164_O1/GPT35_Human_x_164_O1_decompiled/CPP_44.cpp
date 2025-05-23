```cpp
#include <string>
#include <cstdio>

void change_base(std::__cxx11::basic_string* s, int num1, int num2) {
    std::__cxx11::basic_string tmp;
    int remainder = num1 % num2;
    int quotient = num1 / num2;
    
    snprintf(tmp, 16, "%d", remainder);
    
    s->append(tmp.c_str());
    
    if (remainder == 0) {
        std::__cxx11::basic_string tmp2;
        tmp2 = '0';
        s->append(tmp2.c_str());
    } else {
        std::__cxx11::basic_string tmp3;
        tmp3 = '1';
        s->append(tmp3.c_str());
    }
}
```