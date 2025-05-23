#include <string>

using namespace std;

bool correct_bracketing(const string& s) {
    size_t length = s.length();
    if (length == 0) {
        return true;
    }
    
    int balance = 0;
    for (size_t i = 0; i < length; ++i) {
        char c = s[i];
        if (c == '(') {
            balance++;
        } else if (c == ')') {
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
