```cpp
#include <string>
#include <vector>
#include <cstring>

void match_parens(std::string &result, const std::vector<std::string> &input) {
    std::string temp;
    size_t count = 0;
    size_t i = 0;

    while (i < input.size()) {
        const std::string &str = input[i];
        for (char ch : str) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
            }
        }
        
        if (count < 0) {
            temp = "Error: Unmatched parentheses";
            break;
        }
        i++;
    }
    
    if (count == 0) {
        temp = "Yes";
    } else {
        temp = "No";
    }

    result = std::move(temp);
}
```