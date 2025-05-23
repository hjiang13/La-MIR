```cpp
#include <vector>
#include <string>

void separate_paren_groups(std::vector<std::string>& result, const std::string& input) {
    std::string temp;
    for (const char& c : input) {
        if (c == '(') {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
            temp.push_back(c);
            result.push_back(temp);
            temp.clear();
        } else if (c == ')') {
            temp.push_back(c);
            result.push_back(temp);
            temp.clear();
        } else {
            temp.push_back(c);
        }
    }
    if (!temp.empty()) {
        result.push_back(temp);
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){  
    assert (issame(separate_paren_groups("(()()) ((())) () ((())()())"),{"(()())", "((()))", "()", "((())()())"}));
    assert (issame(separate_paren_groups("() (()) ((())) (((())))"), {"()", "(())", "((()))", "(((())))" }));
    assert (issame(separate_paren_groups("(()(())((())))") ,{ "(()(())((())))" }));
    assert (issame(separate_paren_groups("( ) (( )) (( )( ))") ,{"()", "(())", "(()())"}));
}