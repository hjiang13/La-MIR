#include <string.h>

int is_happy(const char* str) {
    int len = strlen(str);
    if (len < 3) return 0;

    for (int i = 2; i < len; i++) {
        if (str[i] == str[i-2]) return 0;
    }
    return 1;
}
