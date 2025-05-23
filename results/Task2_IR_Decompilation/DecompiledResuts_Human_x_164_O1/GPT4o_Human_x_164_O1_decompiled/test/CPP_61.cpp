#include <string>

bool correct_bracketing(const std::string& str) {
    size_t length = str.size();
    if (length == 0) return false;

    int count = 0;
    for (size_t i = 0; i < length; ++i) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        }
        if (count < 0) return false; // More closing brackets
    }
    return count == 0; // Check if all opened brackets are closed
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
