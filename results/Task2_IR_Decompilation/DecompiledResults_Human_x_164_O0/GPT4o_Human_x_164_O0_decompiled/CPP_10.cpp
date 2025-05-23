```cpp
#include <string>
#include <iostream>

bool is_palindrome(const std::string& str) {
    auto rbegin = std::reverse_iterator<std::string::const_iterator>(str.end());
    auto rend = std::reverse_iterator<std::string::const_iterator>(str.begin());
    return std::equal(rbegin, rend, str.begin());
}

std::string make_palindrome(const std::string& str) {
    std::string result = str;
    for (size_t i = 0; i < str.length(); ++i) {
        result += str[str.length() - 1 - i];
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    
    if (is_palindrome(input)) {
        std::cout << "The string is already a palindrome." << std::endl;
    } else {
        std::string palindrome = make_palindrome(input);
        std::cout << "The palindrome is: " << palindrome << std::endl;
    }

    return 0;
}
```