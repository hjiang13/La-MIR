#include <string.h>

int is_happy(const char* str) {
    size_t len = strlen(str);
    if (len < 3) return 0;

    char last_char = str[1];
    for (size_t i = 2; i < len; i++) {
        if (str[i] == last_char) return 1;
        last_char = str[i - 2];
    }
    return 0;
}
