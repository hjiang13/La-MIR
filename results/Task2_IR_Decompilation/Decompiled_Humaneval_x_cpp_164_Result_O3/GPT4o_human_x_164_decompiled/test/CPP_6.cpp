#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>

void parse_nested_parens(std::vector<int>& vec, const std::string& str) {
    std::string temp_str;
    size_t length = str.size();
    size_t index = 0;

    while (index < length) {
        char c = str[index];

        switch (c) {
            case '(':
                vec.push_back(1);  // Increment some counter or state
                break;
            case ')':
                if (vec.empty()) {
                    throw std::length_error("Too many closing parentheses");
                }
                vec.pop_back();  // Decrement some counter or state
                break;
            default:
                temp_str += c;
                break;
        }
        ++index;
    }

    if (!vec.empty()) {
        throw std::length_error("Too many opening parentheses");
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