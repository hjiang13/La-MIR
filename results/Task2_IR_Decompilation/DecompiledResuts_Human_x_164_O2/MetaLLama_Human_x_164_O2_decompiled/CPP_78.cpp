#include <string.h>

int hex_key(const char* str) {
    const char* key = "2357BD";
    int len = strlen(key);
    int result = 0;

    if (strlen(str) == 0) {
        return 0;
    }

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (i < len && key[i] == c) {
            result++;
        } else if (i < len && key[i + 1] == c) {
            result++;
        } else if (i < len && key[i + 2] == c) {
            result++;
        }
    }

    return result;
}
