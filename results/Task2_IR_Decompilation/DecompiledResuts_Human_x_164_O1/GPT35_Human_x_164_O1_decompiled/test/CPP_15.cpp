```cpp
#include <string>

void string_sequence(std::__cxx11::basic_string& s, int n) {
    s = "0";

    std::__cxx11::basic_string s1;
    s1 = s;

    if (n > 15) {
        s1 = std::__cxx11::basic_string(n, '\0');
    } else {
        s1 = s.substr(0, n);
    }

    s = s1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_sequence(0) == "0");
    assert (string_sequence(3) == "0 1 2 3");
     assert (string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10");
}
