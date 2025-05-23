#include <vector>
#include <string>

void separate_paren_groups(std::vector<std::string>& vec, const std::string& input) {
    std::string temp;
    size_t input_length = input.size();
    size_t group_count = 0;

    for (size_t i = 0; i < input_length; ++i) {
        if (input[i] == '(') {
            group_count++;
        } else if (input[i] == ')') {
            group_count--;
        } else {
            temp += input[i];
        }
        if (group_count == 0 && !temp.empty()) {
            vec.push_back(temp);
            temp.clear();
        }
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