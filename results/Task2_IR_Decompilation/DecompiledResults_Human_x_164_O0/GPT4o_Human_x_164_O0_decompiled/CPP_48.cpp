```cpp
#include <string>
#include <iostream>
#include <algorithm>

bool is_palindrome(const std::string& str) {
    auto rbegin = std::reverse_iterator<std::string::const_iterator>(str.end());
    auto rend = std::reverse_iterator<std::string::const_iterator>(str.begin());
    return std::equal(rbegin, rend, str.begin());
}

int main() {
    std::string test_str = "madam";
    if (is_palindrome(test_str)) {
        std::cout << test_str << " is a palindrome." << std::endl;
    } else {
        std::cout << test_str << " is not a palindrome." << std::endl;
    }
    return 0;
}
```