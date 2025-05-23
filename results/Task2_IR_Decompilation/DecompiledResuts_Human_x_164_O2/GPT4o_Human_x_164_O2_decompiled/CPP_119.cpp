```cpp
#include <iostream>
#include <string>
#include <vector>

std::string match_parens(std::string& result, const std::vector<std::string>& vec) {
    std::string temp;
    int count = 0;
    int i = 0;

    while (i < vec.size()) {
        char current = vec[i][0];
        if (current == '(') {
            count++;
        } else if (current == ')') {
            count--;
        }
        temp += current;
        i++;
    }

    if (count == 0) {
        result = temp;
        return result;
    } else {
        result = "Unmatched parentheses";
        return result;
    }
}

int main() {
    std::vector<std::string> vec = {"(", "a", "(", "b", ")", "c", ")"};
    std::string result;
    match_parens(result, vec);
    std::cout << result << std::endl;
    return 0;
}
```