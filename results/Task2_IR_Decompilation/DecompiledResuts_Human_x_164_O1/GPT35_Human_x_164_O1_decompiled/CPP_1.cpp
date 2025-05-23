```cpp
#include <vector>
#include <string>

void separate_paren_groups(std::vector<std::string>& result, const std::string& input) {
    result.clear();
    
    std::string temp;
    for (const char& c : input) {
        if (c == '(') {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        } else if (c == ')') {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        } else {
            temp += c;
        }
    }
    
    if (!temp.empty()) {
        result.push_back(temp);
    }
}

int main() {
    std::string input = "(group1)(group2)(group3)";
    std::vector<std::string> result;
    
    separate_paren_groups(result, input);
    
    for (const std::string& group : result) {
        std::cout << group << std::endl;
    }
    
    return 0;
}
```