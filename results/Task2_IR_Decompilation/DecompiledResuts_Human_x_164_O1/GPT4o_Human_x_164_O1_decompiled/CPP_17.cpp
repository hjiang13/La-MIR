```cpp
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

void parse_music(std::vector<int>& vec, const std::string& str) {
    int len = str.size();
    if (len == 0) return;

    vec.clear();
    for (int i = 0; i < len; ++i) {
        char current_char = str[i];
        if (current_char == 'o') {
            vec.push_back(1);
        } else if (current_char == '|') {
            vec.push_back(2);
        } else if (current_char == '.') {
            vec.push_back(3);
        }
    }
}

int main() {
    std::vector<int> vec;
    std::string input = "o|.|o|";
    parse_music(vec, input);

    for (int v : vec) {
        std::cout << v << " ";
    }
    return 0;
}
```