#include <string>
#include <vector>
#include <stdexcept>

std::vector<int> parse_nested_parens(const std::string& input) {
    std::vector<int> result;
    std::string current;
    int depth = 0;
    int max_depth = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c == '(') {
            ++depth;
            if (depth > max_depth) {
                max_depth = depth;
            }
            current += c;
        } else if (c == ')') {
            --depth;
            current += c;
            if (depth == 0) {
                result.push_back(max_depth);
                current.clear();
                max_depth = 0;
            }
        } else {
            current += c;
        }
    }

    if (!current.empty()) {
        throw std::runtime_error("Unmatched parentheses");
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