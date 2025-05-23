#include <string>

bool check_if_last_char_is_a_letter(const std::string& str) {
    size_t length = str.size();
    if (length == 0) return false;
    
    char lastChar = str[length - 1];
    if (lastChar < 'A') return false;
    if (lastChar > 'Z') {
        if (lastChar < 'a') return false;
        if (lastChar > 'z') return false;
    }
    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (check_if_last_char_is_a_letter("apple") == false);
    assert (check_if_last_char_is_a_letter("apple pi e") == true);
    assert (check_if_last_char_is_a_letter("eeeee") == false);
    assert (check_if_last_char_is_a_letter("A") == true);
    assert (check_if_last_char_is_a_letter("Pumpkin pie ") == false);
    assert (check_if_last_char_is_a_letter("Pumpkin pie 1") == false);
    assert (check_if_last_char_is_a_letter("") == false);
    assert (check_if_last_char_is_a_letter("eeeee e ") == false);
    assert (check_if_last_char_is_a_letter("apple pie") == false);
    assert (check_if_last_char_is_a_letter("apple pi e ") == false);
}
