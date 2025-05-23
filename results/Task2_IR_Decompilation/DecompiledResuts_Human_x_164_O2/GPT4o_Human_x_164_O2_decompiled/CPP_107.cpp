```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

void even_odd_palindrome(std::vector<std::string> &result, int n) {
    if (n < 1) {
        result.push_back("0");
        result.push_back("0");
        return;
    }
    
    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    result.push_back(std::to_string(even_count));
    result.push_back(std::to_string(odd_count));
}

int main() {
    std::vector<std::string> result;
    int n;
    std::cin >> n;
    even_odd_palindrome(result, n);
    
    for (const auto &s : result) {
        std::cout << s << std::endl;
    }
    return 0;
}
```