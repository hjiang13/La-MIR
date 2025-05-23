```c
#include <iostream>
#include <string>

void solve(std::__cxx11::basic_string<char>& s, int n) {
    std::__cxx11::basic_string<char> temp;
    
    char* ptr = &s[0];
    int size = s.size();
    
    if (n > 15) {
        temp = std::__cxx1112basic_stringIcSt11char_traitsIcESaIcEE::_M_create(&s, &size, 0);
        s = temp;
    } else {
        switch (n) {
            case 1:
                s[0] = ptr[0];
                break;
            case 0:
                std::memcpy(&s[0], ptr, n);
                break;
        }
        
        s[1] = size;
        s[size] = '\0';
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solve(1000) == "1");
    assert (solve(150) == "110");
    assert (solve(147) == "1100");
    assert (solve(333) == "1001");
    assert (solve(963) == "10010");
}
