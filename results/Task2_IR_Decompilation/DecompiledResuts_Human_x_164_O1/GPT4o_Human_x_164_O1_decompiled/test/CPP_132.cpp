#include <string>

bool is_nested(const std::string& str) {
    size_t len = str.size();
    if (len == 0) return false;

    size_t count = 0;
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == '[') {
            count++;
        } else if (str[i] == ']') {
            count--;
        }
    }
    return count > 0;
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
