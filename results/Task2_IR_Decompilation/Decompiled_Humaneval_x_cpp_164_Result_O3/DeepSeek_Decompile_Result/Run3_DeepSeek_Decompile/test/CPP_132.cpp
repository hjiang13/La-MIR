#include <string>

using namespace std;

bool is_nested(const string& s) {
    if (s.empty()) {
        return false;
    }
    
    int nesting_level = 0;
    for (char c : s) {
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
