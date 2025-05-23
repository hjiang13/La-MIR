#include <string>
#include <cstring>

bool is_palindrome(std::string str) {
    size_t len = str.length();
    if (len > 15) {
        char* buffer = new char[len + 1];
        memcpy(buffer, str.c_str(), len);
        buffer[len] = '\0';
        str = std::string(buffer);
        delete[] buffer;
    }

    if (len < 4) {
        return true;
    }

    size_t i = 0;
    size_t j = len - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
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
