#include <vector>
#include <string>
#include <iostream>

void separate_paren_groups(std::vector<std::string>& vec, const std::string& str) {
    std::string current;
    int open_parens = 0;
    
    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (c == '(') {
            if (open_parens == 0 && !current.empty()) {
                vec.push_back(current);
                current.clear();
            }
            open_parens++;
        } else if (c == ')') {
            open_parens--;
            if (open_parens < 0) {
                throw std::length_error("Mismatched parentheses");
            }
            if (open_parens == 0) {
                vec.push_back(current);
                current.clear();
            }
        } else {
            current.push_back(c);
        }
    }
    
    if (open_parens != 0) {
        throw std::length_error("Mismatched parentheses");
    }
    
    if (!current.empty()) {
        vec.push_back(current);
    }
}

int main() {
    std::vector<std::string> results;
    std::string input = "Example(input string with (nested (parentheses)) and other text)";
    
    try {
        separate_paren_groups(results, input);
        for (const auto& group : results) {
            std::cout << group << std::endl;
        }
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
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