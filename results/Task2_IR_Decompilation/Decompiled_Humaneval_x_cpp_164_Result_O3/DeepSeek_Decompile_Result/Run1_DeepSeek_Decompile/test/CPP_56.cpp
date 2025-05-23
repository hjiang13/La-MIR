#include <string>

using namespace std;

bool correct_bracketing(const string& s) {
    if (s.empty()) {
        return true;
    }
    int total = 0;
    for (char c : s) {
        if (c == '<') {
            total++;
        } else if (c == '>') {
            total--;
            if (total < 0) {
                return false;
            }
        }
    }
    return total == 0;
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
