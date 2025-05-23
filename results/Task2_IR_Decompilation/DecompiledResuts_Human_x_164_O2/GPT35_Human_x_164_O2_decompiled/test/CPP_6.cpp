```cpp
#include <vector>
#include <string>

void parse_nested_parens(std::vector<int>& result, std::string& input) {
    std::__cxx11::basic_string<char> temp_str;
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '(') {
            result.push_back(i);
        } else if (input[i] == ')') {
            if (!result.empty()) {
                result.pop_back();
            }
        }
    }
}

int main() {
    std::vector<int> result;
    std::__cxx11::basic_string<char> input = "((()))";
    parse_nested_parens(result, input);
    return 0;
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