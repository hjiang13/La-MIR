#include <string>

bool correct_bracketing(const std::string& str) {
    size_t length = str.size();
    if (length == 0) return false;

    int balance = 0;
    for (size_t i = 0; i < length; ++i) {
        char ch = str[i];
        if (ch == '<') {
            balance++;
        } else if (ch == '>') {
            balance--;
        }
        if (balance < 0) return false;
    }
    return balance == 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (correct_bracketing("<>"));
    assert (correct_bracketing("<<><>>"));
    assert (correct_bracketing("<><><<><>><>"));
    assert (correct_bracketing("<><><<<><><>><>><<><><<>>>"));
    assert (not (correct_bracketing("<<<><>>>>")));
    assert (not (correct_bracketing("><<>")));
    assert (not (correct_bracketing("<")));
    assert (not (correct_bracketing("<<<<")));
    assert (not (correct_bracketing(">")));
    assert (not (correct_bracketing("<<>")));
    assert (not (correct_bracketing("<><><<><>><>><<>")));
    assert (not (correct_bracketing("<><><<><>><>>><>")));
}
