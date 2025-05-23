#include <string>

using namespace std;

bool correct_bracketing(const string& s) {
    if (s.empty()) {
        return true;
    }

    int balance = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')') {
            balance--;
        }
        
        if (balance < 0) {
            return false;
        }
    }

    return balance == 0;
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
