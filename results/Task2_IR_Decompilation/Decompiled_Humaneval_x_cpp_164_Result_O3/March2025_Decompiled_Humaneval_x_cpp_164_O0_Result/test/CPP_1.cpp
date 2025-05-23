#include <vector>
#include <string>

std::vector<std::string> separate_paren_groups(const std::string &input) {
    std::vector<std::string> result;
    std::string current_group;
    int paren_count = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        current_group += c;

        if (c == '(') {
            ++paren_count;
        } else if (c == ')') {
            --paren_count;
            if (paren_count == 0) {
                result.push_back(current_group);
                current_group.clear();
            }
        }
    }

    return result;
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