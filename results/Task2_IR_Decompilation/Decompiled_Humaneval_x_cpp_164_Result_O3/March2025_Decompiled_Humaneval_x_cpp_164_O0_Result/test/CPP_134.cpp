#include <string>

bool check_if_last_char_is_a_letter(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    char lastChar = str.back();
    if ((lastChar >= 'A' && lastChar <= 'Z') || (lastChar >= 'a' && lastChar <= 'z')) {
        if (str.length() == 1) {
            return true;
        }

        char secondLastChar = str[str.length() - 2];
        if ((secondLastChar >= 'A' && secondLastChar <= 'Z') || (secondLastChar >= 'a' && secondLastChar <= 'z')) {
            return false;
        } else {
            return true;
        }
    }

    return false;
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
