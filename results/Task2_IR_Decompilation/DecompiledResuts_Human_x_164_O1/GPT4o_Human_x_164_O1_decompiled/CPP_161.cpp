```cpp
#include <string>

void solve(std::string &result, const std::string &input) {
    size_t len = input.length();
    if (len == 0) return;

    char *res = new char[len + 1];
    size_t i = 0;

    for (size_t j = 0; j < len; ++j) {
        char ch = input[j];
        if (ch >= 'A' && ch <= 'Z') {
            res[i++] = ch + 32; // Convert to lowercase
        } else if (ch >= 'a' && ch <= 'z') {
            res[i++] = ch - 32; // Convert to uppercase
        } else {
            res[i++] = ch; // Copy other characters
        }
    }
    
    res[i] = '\0';
    result = std::string(res);
    delete[] res;
}

int main() {
    std::string input = "Hello World!";
    std::string output;
    solve(output, input);
    return 0;
}
```