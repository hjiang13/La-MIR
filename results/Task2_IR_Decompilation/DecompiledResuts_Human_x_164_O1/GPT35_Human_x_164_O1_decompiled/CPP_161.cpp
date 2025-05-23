```cpp
#include <string>

void solve(std::__cxx11::basic_string<char>& s, std::__cxx11::basic_string<char>& input) {
    std::__cxx11::basic_string<char> temp;
    
    for (int i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        } else if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        temp += c;
    }
    
    s = temp;
}
```