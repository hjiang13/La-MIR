#include <string>

void string_sequenceB5cxx11(std::__cxx11::basic_string& s, int num) {
    s.clear();
    s.append(" ");
    if (num < 1) {
        return;
    }

    std::__cxx11::basic_string str;
    str.append(std::__cxx11::basic_string<char>::_Alloc_hider(1), 1);

    switch (num) {
        case 1:
            s.append(str);
            break;
        case 0:
            break;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_sequence(0) == "0");
    assert (string_sequence(3) == "0 1 2 3");
     assert (string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10");
}
