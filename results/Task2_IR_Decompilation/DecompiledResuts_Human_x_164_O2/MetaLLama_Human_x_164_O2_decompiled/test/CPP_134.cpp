#include <stdbool.h>
#include <stdint.h>

bool check_if_last_char_is_a_letter(const char* str, uint64_t length) {
    if (length == 0) {
        return false;
    }

    uint64_t last_char_index = length - 1;
    char last_char = str[last_char_index];

    if (last_char < 65) {
        return false;
    }

    if (last_char > 90) {
        uint8_t shifted = last_char - 91;
        uint64_t mask = 133143986239 >> shifted;
        if (mask & 1) {
            return false;
        }
    } else {
        if (length == 1) {
            return true;
        }

        uint64_t second_last_char_index = length - 2;
        char second_last_char = str[second_last_char_index];
        uint8_t diff = second_last_char - 65;

        if (diff < 26) {
            return true;
        }

        diff = second_last_char - 97;
        return diff > 25;
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
