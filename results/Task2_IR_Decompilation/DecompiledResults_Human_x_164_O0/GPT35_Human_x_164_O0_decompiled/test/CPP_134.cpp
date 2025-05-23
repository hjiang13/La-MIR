```c++
#include <string>

using namespace std;

bool check_if_last_char_is_a_letter(string* str) {
    bool result;
    if (str->length() == 0) {
        result = false;
    } else {
        char last_char = (*str)[str->length() - 1];
        if ((last_char < 65) || (last_char > 90 && last_char < 97) || (last_char > 122)) {
            result = false;
        } else {
            result = true;
        }
    }
    return result;
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
