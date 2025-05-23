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
