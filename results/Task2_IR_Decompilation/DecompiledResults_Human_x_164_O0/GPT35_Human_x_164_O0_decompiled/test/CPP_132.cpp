```c
#include <string>

bool is_nested(std::basic_string<char> *str) {
    bool result = false;
    int index = 0;
    int open_brackets = 0;
    int close_brackets = 0;

    while (index < str->length()) {
        char current_char = (*str)[index];
        if (current_char == '[') {
            open_brackets++;
        } else if (current_char == ']') {
            close_brackets++;
        }

        if (close_brackets > open_brackets) {
            result = true;
            break;
        }

        index++;
    }

    return result;
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
