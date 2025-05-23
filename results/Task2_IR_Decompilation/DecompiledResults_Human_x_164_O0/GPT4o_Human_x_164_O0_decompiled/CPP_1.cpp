```cpp
#include <vector>
#include <string>

void separate_paren_groups(std::vector<std::string>& result, const std::string& str) {
    bool is_inside_paren = false;
    std::string temp;

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == '(') {
            if (is_inside_paren) {
                temp += ch;
            }
            is_inside_paren = true;
            continue;
        }
        if (ch == ')') {
            if (is_inside_paren) {
                temp += ch;
                if (temp.length() > 0) {
                    result.push_back(temp);
                    temp.clear();
                }
            }
            is_inside_paren = false;
            continue;
        }

        if (is_inside_paren) {
            temp += ch;
        }
    }
}
```