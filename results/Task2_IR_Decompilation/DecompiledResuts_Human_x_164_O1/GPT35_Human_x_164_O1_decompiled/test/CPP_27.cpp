```cpp
#include <string>

void filp_case(std::__cxx11::basic_string<char>& str) {
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            str[i] = c - 32;
        } else if (c >= 'A' && c <= 'Z') {
            str[i] = c + 32;
        }
    }
}

int main() {
    std::__cxx11::basic_string<char> str = "Hello World";
    filp_case(str);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
