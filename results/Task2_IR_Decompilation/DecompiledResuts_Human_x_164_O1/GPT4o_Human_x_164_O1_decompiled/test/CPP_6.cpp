#include <vector>
#include <string>
#include <iostream>

void parse_nested_parens(std::vector<int>& vec, const std::string& str) {
    std::string tempStr;
    size_t i = 0;
    size_t len = str.size();
    int count = 0;

    while (i < len) {
        char ch = str[i];
        if (ch == '(') {
            count++;
        } else if (ch == ')') {
            count--;
        } else if (ch == ' ') {
            // Ignore spaces
        } else {
            tempStr += ch;
        }

        if (count == 0 && !tempStr.empty()) {
            vec.push_back(tempStr.size());
            tempStr.clear();
        }
        i++;
    }
}

int main() {
    std::vector<int> result;
    std::string input = "((a)(b)) ((c)(d))";
    parse_nested_parens(result, input);

    for (int size : result) {
        std::cout << size << std::endl;
    }
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