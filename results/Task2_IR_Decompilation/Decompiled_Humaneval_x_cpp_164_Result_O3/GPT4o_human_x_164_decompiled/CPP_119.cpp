```cpp
#include <string>
#include <vector>

std::string match_parens(std::string &result, const std::vector<std::string> &input) {
    int len = input.size();
    if (len <= 0) {
        result = "Yes";
        return result;
    }

    std::string temp;
    for (int i = 0; i < len; ++i) {
        temp += input[i];
    }

    int balance = 0;
    for (char ch : temp) {
        if (ch == '(') {
            balance++;
        } else if (ch == ')') {
            balance--;
        }
        if (balance < 0) {
            result = "No";
            return result;
        }
    }

    result = (balance == 0) ? "Yes" : "No";
    return result;
}
```