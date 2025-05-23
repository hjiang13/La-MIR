```cpp
#include <string>
#include <vector>

void match_parens(std::string& s, std::vector<std::string>& v) {
    std::string temp;
    for (auto& str : v) {
        temp = str.substr(1, str.size() - 2);
        s += temp;
    }
}

int main() {
    std::vector<std::string> input = { "Yes" };
    std::string result;
    match_parens(result, input);
    return 0;
}
```