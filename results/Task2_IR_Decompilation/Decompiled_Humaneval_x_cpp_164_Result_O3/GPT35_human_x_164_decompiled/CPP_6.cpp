```c++
#include <vector>
#include <string>

void parse_nested_parens(std::vector<int>& v, std::string& s) {
    std::__cxx11::basic_string<char> str;
    v.clear();
    str._M_mutate(0, 0, nullptr, 1);
    
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(') {
            v.push_back(1);
            str._M_mutate(0, 1, nullptr, 1);
        } else if (c == ')') {
            v.pop_back();
            str._M_mutate(0, 1, nullptr, 1);
        }
    }
}

int main() {
    std::vector<int> v;
    std::string s = "((()))";
    parse_nested_parens(v, s);
    
    return 0;
}
```