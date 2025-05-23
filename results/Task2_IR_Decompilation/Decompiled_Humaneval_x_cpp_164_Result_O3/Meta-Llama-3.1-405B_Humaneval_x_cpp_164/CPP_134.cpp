#include <stdbool.h>

bool check_if_last_char_is_a_letter(const char* str, long length) {
    if (length == 0) {
        return false;
    }

    long index = length - 1;
    char last_char = str[index];

    if (last_char < 65) {
        return false;
    }

    if (last_char > 90) {
        long shifted = (unsigned char)last_char - 91;
        long mask = 133143986239 >> shifted;
        if ((mask & 1) == 0) {
            if (length == 1) {
                return false;
            }

            index -= 1;
            char second_last_char = str[index];

            if (second_last_char >= 65 && second_last_char <= 90) {
                return false;
            }

            if (second_last_char >= 97 && second_last_char <= 122) {
                return true;
            }
        }
    } else if (length > 1) {
        index -= 1;
        char second_last_char = str[index];

        if (second_last_char >= 65 && second_last_char <= 90) {
            return false;
        }
    }

    return false;
}
