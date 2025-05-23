#include <string.h>

int same_chars(const char* s1, const char* s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (len1 == 0 || len2 == 0) {
        return len1 == len2;
    }

    size_t i = 0;
    while (i < len1 && i < len2) {
        if (s1[i] != s2[i]) {
            break;
        }
        ++i;
    }

    if (i == len1 || i == len2) {
        return len1 == len2;
    }

    if (len1 > 3 && len2 > 3) {
        size_t j = 0;
        while (j < len2) {
            if (s1[i] == s2[j]) {
                break;
            }
            ++j;
        }

        if (j == len2) {
            return 0;
        }

        size_t k = 0;
        while (k < len1) {
            if (s1[k] != s2[j]) {
                break;
            }
            ++k;
            ++j;
        }

        return k == len1 && j == len2;
    }

    size_t j = len2 - 1;
    while (j >= i) {
        if (s1[i] == s2[j]) {
            break;
        }
        --j;
    }

    if (j < i) {
        return 0;
    }

    size_t k = len1 - 1;
    while (k >= i) {
        if (s1[k] != s2[j]) {
            break;
        }
        --k;
        --j;
    }

    return k < i && j < i;
}
