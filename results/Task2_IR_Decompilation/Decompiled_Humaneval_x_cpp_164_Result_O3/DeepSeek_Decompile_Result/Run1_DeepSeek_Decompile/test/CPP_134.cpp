#include <string>

using namespace std;

bool check_if_last_char_is_a_letter(const string& s) {
    size_t length = s.length();
    if (length == 0) {
        return false;
    }

    char last_char = s[length - 1];
    if (last_char < 'A') {
        return false;
    }

    if (last_char > 'Z') {
        if (length == 1) {
            return false;
        }

        char second_last = s[length - 2];
        if (second_last >= 'A' && second_last <= 'Z') {
            return false;
        }

        if (last_char > 'z') {
            return false;
        }
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
