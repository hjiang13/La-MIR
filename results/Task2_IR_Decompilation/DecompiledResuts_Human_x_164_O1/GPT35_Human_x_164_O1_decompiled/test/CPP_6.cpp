```cpp
#include <vector>
#include <string>

void parse_nested_parens(std::vector<int>& result, const std::string& input) {
    std::string temp;
    int count = 0;
    
    for (char c : input) {
        if (c == '(') {
            count++;
        } else if (c == ')' && count > 0) {
            count--;
        }
        
        if (count > 0) {
            temp += c;
        } else if (!temp.empty()) {
            result.push_back(std::stoi(temp));
            temp.clear();
        }
    }
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