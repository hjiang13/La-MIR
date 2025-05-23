#include <stdbool.h>
#include <stdint.h>

bool correct_bracketing(const char *s, uint64_t length) {
    if (length == 0) {
        return true;
    }

    int depth = 0;
    for (uint64_t i = 0; i < length; i++) {
        char c = s[i];
        if (c == '<') {
            depth++;
        } else if (c == '>') {
            depth--;
        }
        if (depth < 0) {
            return false;
        }
    }

    return depth == 0;
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
