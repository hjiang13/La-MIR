```c++
#include <string>

void filp_case(std::__cxx11::basic_string<char>& s1, std::__cxx11::basic_string<char>& s2) {
    s1.clear();
    for (size_t i = 0; i < s2.size(); i++) {
        char c = s2[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        } else if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
        s1.push_back(c);
    }
}

int main() {
    std::__cxx11::basic_string<char> s1, s2;
    // Populate s2 with some string
    filp_case(s1, s2);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
