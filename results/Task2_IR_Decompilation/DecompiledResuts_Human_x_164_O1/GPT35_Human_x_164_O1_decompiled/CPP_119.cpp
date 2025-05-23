```c++
#include <iostream>
#include <string>
#include <vector>

void match_parens(std::string& result, std::vector<std::string>& input) {
    for (const auto& str : input) {
        for (char c : str) {
            if (c == '(') {
                result.push_back(c);
            } else if (c == ')') {
                if (!result.empty() && result.back() == '(') {
                    result.pop_back();
                } else {
                    result.push_back(c);
                }
            }
        }
    }
}

int main() {
    std::vector<std::string> input = {"(a+b)", "((c+d))", "e+f)", "(g+h)"};
    std::string result;
    match_parens(result, input);

    if (result.empty()) {
        std::cout << "Parentheses matched correctly" << std::endl;
    } else {
        std::cout << "Unbalanced parentheses detected" << std::endl;
    }

    return 0;
}
```