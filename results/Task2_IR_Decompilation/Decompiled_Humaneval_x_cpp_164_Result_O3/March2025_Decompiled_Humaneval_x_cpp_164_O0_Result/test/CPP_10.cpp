#include <string>
#include <algorithm>

bool is_palindrome(const std::string& str) {
    std::string reversed_str(str.rbegin(), str.rend());
    return reversed_str == str;
}

void make_palindrome(std::string& result, const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        std::string substr = str.substr(i);
        if (is_palindrome(substr)) {
            result = str.substr(0, i) + std::string(substr.rbegin(), substr.rend());
            return;
        }
    }
    result = str + std::string(str.rbegin(), str.rend());
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (make_palindrome("") == "");
    assert (make_palindrome("x") == "x");
     assert (make_palindrome("xyz") == "xyzyx");
     assert (make_palindrome("xyx") == "xyx") ;
     assert (make_palindrome("jerry") == "jerryrrej");
}


