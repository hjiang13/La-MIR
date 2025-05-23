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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_palindrome("") == true);
    assert (is_palindrome("aba") == true);
    assert (is_palindrome("aaaaa") == true);
    assert (is_palindrome("zbcd") == false);
    assert (is_palindrome("xywyx") == true);
    assert (is_palindrome("xywyz") == false);
    assert (is_palindrome("xywzx") == false);
}
