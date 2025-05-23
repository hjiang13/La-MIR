#include <cstring>
#include <string>

bool is_palindrome(const std::string& str) {
    size_t len = str.size();
    if (len <= 15) {
        return len == 0;
    }
    size_t left = 0, right = len - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

std::string make_palindrome(const std::string& str) {
    size_t len = str.size();
    std::string result;
    result.reserve(len * 2 + 1);

    for (size_t i = 0; i < len; ++i) {
        result += str[i];
    }
    for (size_t i = len; i > 0; --i) {
        result += str[i - 1];
    }
    return result;
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


