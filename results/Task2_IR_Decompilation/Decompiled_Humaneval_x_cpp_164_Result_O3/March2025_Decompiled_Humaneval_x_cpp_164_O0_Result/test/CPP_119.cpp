#include <iostream>
#include <string>
#include <vector>

std::string match_parens(std::vector<std::string> &vec) {
    std::string result = vec[0] + vec[1];
    int balance = 0;
    bool valid = true;

    for (size_t i = 0; i < result.length(); ++i) {
        if (result[i] == '(') {
            ++balance;
        } else if (result[i] == ')') {
            --balance;
            if (balance < 0) {
                valid = false;
                break;
            }
        }
    }

    if (balance != 0) {
        return "No";
    }

    return valid ? "Yes" : "No";
}

int main() {
    std::vector<std::string> vec = {"(", ")"};
    std::string result = match_parens(vec);
    std::cout << result << std::endl;
    return 0;
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
