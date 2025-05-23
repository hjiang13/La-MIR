```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

void even_odd_palindrome(std::vector<std::string>& result, int n) {
    if (n < 1) {
        result.resize(2);
        result[0] = "";
        result[1] = "";
        return;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        std::string str = "string" + std::to_string(i);
        bool is_palindrome = true;
        int len = str.length();
        for (int j = 0; j < len / 2; ++j) {
            if (str[j] != str[len - j - 1]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            count++;
        }
    }

    result.resize(2);
    result[0] = "Count of palindromes: " + std::to_string(count);
    result[1] = "Count of non-palindromes: " + std::to_string(n - count);
}

int main() {
    std::vector<std::string> result;
    even_odd_palindrome(result, 10);
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }
    return 0;
}
```