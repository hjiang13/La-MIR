```c
#include <stdint.h>

int check_if_last_char_is_a_letter(const char* str) {
    int len = strlen(str);
    if (len == 0) {
        return 0;
    }
    char last_char = str[len - 1];
    if (last_char < 'A' || last_char > 'Z') {
        if (last_char < 'a' || last_char > 'z') {
            return 0;
        }
    }
    return 1;
}

```