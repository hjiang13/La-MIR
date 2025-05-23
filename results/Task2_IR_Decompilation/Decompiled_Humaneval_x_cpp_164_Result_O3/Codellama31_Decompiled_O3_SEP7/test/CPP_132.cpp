#include <string>

bool _Z9is_nestedNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(std::__cxx11::basic_string<char>* str) {
    int level = 0;
    for (int i = 0; i < str->length(); i++) {
        if (str[i] == '(') {
            level++;
        } else if (str[i] == ')') {
            level--;
        }
        if (level < 0) {
            return false;
        }
    }
    return level == 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_nested("[[]]") == true);
    assert (is_nested("[]]]]]]][[[[[]") == false);
    assert (is_nested("[][]") == false);
    assert (is_nested(("[]")) == false);
    assert (is_nested("[[[[]]]]") == true);
    assert (is_nested("[]]]]]]]]]]") == false);
    assert (is_nested("[][][[]]") == true);
    assert (is_nested("[[]") == false);
    assert (is_nested("[]]") == false);
    assert (is_nested("[[]][[") == true);
    assert (is_nested("[[][]]") == true);
    assert (is_nested("") == false);
    assert (is_nested("[[[[[[[[") == false);
    assert (is_nested("]]]]]]]]") == false);
}
