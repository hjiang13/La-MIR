#include <string>

bool is_nested(const std::string& str) {
    int balance = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '[') {
            balance++;
        } else if (str[i] == ']') {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
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
