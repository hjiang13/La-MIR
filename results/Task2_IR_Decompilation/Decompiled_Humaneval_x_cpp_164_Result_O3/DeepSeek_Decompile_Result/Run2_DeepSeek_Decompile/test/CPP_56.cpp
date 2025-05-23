#include <string>

using namespace std;

bool correct_bracketing(const string& s) {
    if (s.empty()) {
        return true;
    }

    int open = 0, close = 0;
    for (char c : s) {
        if (c == '<') {
            open++;
        } else if (c == '>') {
            close++;
        }

        if (close > open) {
            return false;
        }
    }

    return open == close;
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
