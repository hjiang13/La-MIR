#include <string>

using namespace std;

bool is_nested(const string& s) {
    size_t length = s.length();
    if (length == 0) return false;

    char first_char = s[0];
    if (first_char == '[' || first_char == ']') {
        // Initial checks for the first character
        if (first_char == ']' || (s.back() == '[')) {
            return false;
        }
    }

    size_t nesting_level = 0;
    for (size_t i = 1; i < length; ++i) {
        char c = s[i];
        if (c == '[') {
            nesting_level++;
        } else if (c == ']') {
            nesting_level--;
            if (nesting_level < 0) {
                return false;
            }
        }
    }

    return nesting_level == 0;
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
