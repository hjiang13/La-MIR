#include <string>

using namespace std;

bool correct_bracketing(string brackets) {
    int level = 0;
    for (int i = 0; i < brackets.length(); i++) {
        if (brackets[i] == '(') {
            level += 1;
        } else if (brackets[i] == ')') {
            level -= 1;
        }
        if (level < 0) {
            return false;
        }
    }
    if (level != 0) {
        return false;
    }
    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (remove_vowels("") == "");
    assert (remove_vowels("abcdef\nghijklm") == "bcdf\nghjklm");
    assert (remove_vowels("fedcba") == "fdcb");
    assert (remove_vowels("eeeee") == "");
    assert (remove_vowels("acBAA") == "cB");
    assert (remove_vowels("EcBOO") == "cB");
    assert (remove_vowels("ybcd") == "ybcd");
}
