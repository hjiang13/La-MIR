```cpp
#include <vector>
#include <string>

void parse_nested_parens(std::vector<int>& result, const std::string& input) {
    std::string temp;
    int count = 0;
    
    for (char c : input) {
        if (c == '(') {
            count++;
        } else if (c == ')' && count > 0) {
            count--;
        }
        
        if (count > 0) {
            temp += c;
        } else if (!temp.empty()) {
            result.push_back(std::stoi(temp));
            temp.clear();
        }
    }
}
```