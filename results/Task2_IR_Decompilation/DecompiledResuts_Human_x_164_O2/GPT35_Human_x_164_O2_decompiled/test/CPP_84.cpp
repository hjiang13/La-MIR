```C++
#include <cstdio>
#include <string>

void solveB5cxx11i(std::__cxx11::basic_string& s, int n) {
    std::__cxx11::basic_string temp;
    char* ptr = &s[0];
    char* tempPtr = &temp[0];
    
    if (n > 15) {
        temp = std::__cxx11::basic_string(ptr, n);
    } else {
        switch(n) {
            case 1:
                *tempPtr = *ptr;
                break;
            case 0:
                std::memcpy(tempPtr, ptr, n);
                break;
        }
    }
    
    s = temp;
}

int main() {
    std::__cxx11::basic_string s;
    solveB5cxx11i(s, 10);
    
    return 0;
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
