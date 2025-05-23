```c
#include <string>
#include <stdexcept>

void string_sequence(std::string& s, int n) {
    std::string temp = "0";
    for (int i = 1; i <= n; i++) {
        std::string num = std::to_string(i);
        temp += " " + num;
    }
    s = temp;
}

int main() {
    std::string result;
    string_sequence(result, 5);
    return 0;
}
```