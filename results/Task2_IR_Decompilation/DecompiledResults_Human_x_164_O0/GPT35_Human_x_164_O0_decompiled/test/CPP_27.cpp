#include <string>

void _Z9filp_caseNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(std::__cxx11::basic_string<char>&, std::__cxx11::basic_string<char>&);

void _Z9filp_caseNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(std::__cxx11::basic_string<char>& sret, std::__cxx11::basic_string<char>& s) {
    std::allocator<char> a;
    std::__cxx11::basic_string<char> temp;
    temp = " ";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        temp.append(1, c);
    }
    sret = temp;
}

int main() {
    std::__cxx11::basic_string<char> s1 = "hello";
    std::__cxx11::basic_string<char> s2;
    _Z9filp_caseNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(s2, s1);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
