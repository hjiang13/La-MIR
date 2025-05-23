#include <string>

using namespace std;

bool is_nested(const string& s) {
    size_t size = s.size();
    if (size == 0) {
        return false;
    }

    char first = s[0];
    int bracket_count = 0;

    if (first == '[' || first == ']') {
        bracket_count = 1;
    }

    size_t i = 1;
    while (i < size) {
        if (s[i] == '[' || s[i] == ']') {
            if (bracket_count == 0) {
                bracket_count = 1;
            } else {
                bracket_count++;
            }
        }
        i++;
    }

    return bracket_count > 0;
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
