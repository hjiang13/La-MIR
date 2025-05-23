#include <string>
#include <stdexcept>

bool is_palindrome(const std::string& str) {
    std::string reversed(str.rbegin(), str.rend());
    return reversed == str;
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
