```cpp
#include <vector>
#include <string>

void separate_paren_groups(std::vector<std::string>& result, const std::string& input) {
    std::string temp;
    for (const char& c : input) {
        if (c == '(') {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
            temp.push_back(c);
            result.push_back(temp);
            temp.clear();
        } else if (c == ')') {
            temp.push_back(c);
            result.push_back(temp);
            temp.clear();
        } else {
            temp.push_back(c);
        }
    }
    if (!temp.empty()) {
        result.push_back(temp);
    }
}
```