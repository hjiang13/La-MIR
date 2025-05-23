#include <vector>
#include <string>

void separate_paren_groups(std::vector<std::string>& result, const std::string& input) {
    result.clear();
    std::string temp;
    
    for (const char& c : input) {
        if (c == '(') {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
            temp.push_back(c);
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

int main() {
    std::vector<std::string> result;
    std::string input = "((a + b) + (c + d))";
    
    separate_paren_groups(result, input);
    
    for (const std::string& group : result) {
        std::cout << group << std::endl;
    }
    
    return 0;
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