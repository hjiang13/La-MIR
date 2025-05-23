#include <vector>
#include <string>

std::vector<int> parse_nested_parens(std::string str) {
    std::vector<int> result;
    int level = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            level++;
        } else if (str[i] == ')') {
            level--;
            if (level < 0) {
                return result;
            }
        }
        if (level == 0) {
            result.push_back(i);
        }
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(parse_nested_parens("(()()) ((())) () ((())()())"),{2, 3, 1, 3}));
     assert (issame(parse_nested_parens("() (()) ((())) (((())))") , {1, 2, 3, 4}));
    assert (issame(parse_nested_parens("(()(())((())))") ,{4}));
}