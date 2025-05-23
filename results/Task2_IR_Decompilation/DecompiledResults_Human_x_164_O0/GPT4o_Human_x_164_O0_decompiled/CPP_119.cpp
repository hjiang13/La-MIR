```cpp
#include <vector>
#include <string>
#include <iostream>

void match_parens(std::string &result, std::vector<std::string> &vec) {
    int count = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec[i].length(); ++j) {
            char ch = vec[i][j];
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
            }
        }
    }
    if (count > 0) {
        result = "No";
    } else {
        result = "Yes";
    }
}

int main() {
    std::vector<std::string> vec = {"(())", "(()", "())", "()()"};
    std::string result;
    match_parens(result, vec);
    std::cout << result << std::endl;
    return 0;
}
```