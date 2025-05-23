#include <string>

using namespace std;

bool correct_bracketing(const string& s) {
    if (s.empty()) {
        return true;
    }

    int counter = 0;
    for (char c : s) {
        if (c == '(') {
            counter++;
        } else if (c == ')') {
            counter--;
            if (counter < 0) {
                return false;
            }
        }
    }

    return counter == 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (correct_bracketing("()"));
    assert (correct_bracketing("(()())"));
    assert (correct_bracketing("()()(()())()"));
    assert (correct_bracketing("()()((()()())())(()()(()))"));
    assert (not (correct_bracketing("((()())))")));
    assert (not (correct_bracketing(")(()")));
    assert (not (correct_bracketing("(")));
    assert (not (correct_bracketing("((((")));
    assert (not (correct_bracketing(")")));
    assert (not (correct_bracketing("(()")));
    assert (not (correct_bracketing("()()(()())())(()")));
    assert (not (correct_bracketing("()()(()())()))()")));
}
