```cpp
#include <iostream>
#include <vector>
#include <string>

void separate_paren_groups(std::vector<std::string>& vec, const std::string& str) {
    vec.clear();
    size_t n = str.size();
    size_t count = 0;
    size_t index = 0;

    while (index < n) {
        if (str[index] == '(') {
            count++;
        } else if (str[index] == ')') {
            count--;
        }
        index++;

        if (count == 0) {
            vec.push_back(str.substr(0, index));
            str = str.substr(index);
            n = str.size();
            index = 0;
        }
    }
}

int main() {
    std::vector<std::string> results;
    std::string input = "((a+b)*(c+d))((e+f)*(g+h))";
    separate_paren_groups(results, input);

    for (const auto& group : results) {
        std::cout << group << std::endl;
    }

    return 0;
}
```