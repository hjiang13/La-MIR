#include <string>

bool is_nested(const std::string& str) {
    int open_count = 0;
    int max_open_count = 0;
    int index = 0;

    while (index < str.length()) {
        if (str[index] == '[') {
            open_count++;
        } else if (str[index] == ']') {
            open_count--;
            if (open_count < 0) {
                open_count = 0;
            }
        }
        if (open_count > max_open_count) {
            max_open_count = open_count;
        }
        if (open_count <= max_open_count - 2) {
            return true;
        }
        index++;
    }
    return false;
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
