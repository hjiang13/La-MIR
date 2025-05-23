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
```