#include <string>

using namespace std;

bool check_if_last_char_is_a_letter(basic_string<char> str) {
    if (str.empty()) {
        return false;
    }
    char lastChar = str[str.length() - 1];
    return (lastChar >= 'a' && lastChar <= 'z') || (lastChar >= 'A' && lastChar <= 'Z');
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
