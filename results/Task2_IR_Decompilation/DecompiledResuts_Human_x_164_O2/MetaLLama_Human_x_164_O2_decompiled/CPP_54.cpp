#include <stdbool.h>
#include <string.h>

bool same_chars(const char* s1, const char* s2, size_t len1, size_t len2) {
    if (len1 == 0) {
        return len2 == 0;
    }

    if (len2 == 0) {
        return false;
    }

    size_t i = 0;
    size_t j = 0;

    while (i < len1 && j < len2) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else if (j + 3 < len2 && s1[i] == s2[j + 3]) {
            j += 4;
        } else if (j + 2 < len2 && s1[i] == s2[j + 2]) {
            j += 3;
        } else if (j + 1 < len2 && s1[i] == s2[j + 1]) {
            j += 2;
        } else {
            return false;
        }
    }

    return i == len1 && j == len2;
}

bool same_chars_str(const char* s1, const char* s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    return same_chars(s1, s2, len1, len2);
}
