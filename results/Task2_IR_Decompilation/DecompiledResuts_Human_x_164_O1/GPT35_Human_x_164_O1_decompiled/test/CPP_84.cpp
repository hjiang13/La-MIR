```cpp
#include <string>
#include <cstdio>

void solve(std::__cxx11::basic_string& s, int val) {
    std::__cxx11::basic_string temp;
    char* ptr = &temp._M_dataplus._M_p;
    
    snprintf(ptr, 16, "%d", val);
    
    s = temp;
}

int main() {
    std::__cxx11::basic_string str;
    
    solve(str, 123);
    
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
