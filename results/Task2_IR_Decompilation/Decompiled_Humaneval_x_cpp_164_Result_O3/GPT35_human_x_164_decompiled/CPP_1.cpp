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
            temp.push_back(c);
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

int main() {
    std::vector<std::string> result;
    std::string input = "((a + b) + (c + d))";
    
    separate_paren_groups(result, input);
    
    for (const std::string& group : result) {
        std::cout << group << std::endl;
    }
    
    return 0;
}
```