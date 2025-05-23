#include <string>
#include <vector>

void match_parens(std::string& s, std::vector<std::string>& v) {
    std::string temp;
    for (auto str : v) {
        for (char c : str) {
            if (c == '(' || c == ')') {
                temp += c;
            }
        }
    }
    s = temp;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (match_parens({"()(", ")"}) == "Yes");
    assert (match_parens({")", ")"}) == "No");
    assert (match_parens({"(()(())", "())())"}) == "No");
    assert (match_parens({")())", "(()()("}) == "Yes");
    assert (match_parens({"(())))", "(()())(("}) == "Yes");
    assert (match_parens({"()", "())"}) == "No");
    assert (match_parens({"(()(", "()))()"}) == "Yes");
    assert (match_parens({"((((", "((())"}) == "No");
    assert (match_parens({")(()", "(()("}) == "No");
    assert (match_parens({")(", ")("}) == "No");
    assert (match_parens({"(", ")"}) == "Yes");
    assert (match_parens({")", "("}) == "Yes" );
}
