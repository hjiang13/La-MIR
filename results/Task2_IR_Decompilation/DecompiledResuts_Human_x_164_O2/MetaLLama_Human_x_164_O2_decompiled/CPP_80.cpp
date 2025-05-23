#include <string.h>

int is_happy(const char *str) {
    size_t len = strlen(str);
    if (len < 3) return 0;

    char c1 = str[1];
    char c2 = str[2];
    if (c1 == c2) return 1;

    size_t i = 2;
    bool match = true;
    while (i < len) {
        char c = str[i];
        if (c == str[i - 2]) return 1;
        match = (c == c1);
        i++;
    }

    return !match;
}
