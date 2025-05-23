```cpp
#include <string>
#include <iostream>

void fix_spaces(std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == ' ') {
            result += (i > 0 && input[i - 1] != ' ') ? ' ' : '\0';
        } else {
            result += input[i];
        }
    }
    input = result;
}

int main() {
    std::string str = " Hello   World! ";
    fix_spaces(str);
    std::cout << "'" << str << "'" << std::endl;
    return 0;
}
```