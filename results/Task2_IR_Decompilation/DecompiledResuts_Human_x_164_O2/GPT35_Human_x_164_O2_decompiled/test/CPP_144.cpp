```cpp
#include <string>

bool simplify(std::__cxx11::basic_string<char> &str1, std::__cxx11::basic_string<char> &str2) {
    if (str1.size() == 0) {
        return false;
    }

    int pos = 0;
    while (pos < str1.size() && str1[pos] == '/') {
        pos++;
    }

    if (pos == str1.size()) {
        return false;
    }

    std::__cxx11::basic_string<char> substr1 = str1.substr(pos);
    std::__cxx11::basic_string<char> substr2 = str2.substr(pos);

    if (substr1.size() > substr2.size()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::__cxx11::basic_string<char> str1 = "example/string/1";
    std::__cxx11::basic_string<char> str2 = "example/string/2";

    bool result = simplify(str1, str2);

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (simplify("1/5", "5/1") == true);
    assert (simplify("1/6", "2/1") == false);
    assert (simplify("5/1", "3/1") == true);
    assert (simplify("7/10", "10/2") == false);
    assert (simplify("2/10", "50/10") == true);
    assert (simplify("7/2", "4/2") == true);
    assert (simplify("11/6", "6/1") == true);
    assert (simplify("2/3", "5/2") == false);
    assert (simplify("5/2", "3/5") == false);
    assert (simplify("2/4", "8/4") == true);
    assert (simplify("2/4", "4/2") == true);
    assert (simplify("1/5", "5/1") == true);
    assert (simplify("1/5", "1/5") == false);
}
