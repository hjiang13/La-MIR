#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int how_many_times(const char* s1, const char* s2) {
    int count = 0;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (len1 == 0) {
        return 0;
    }

    for (size_t i = 0; i <= len1 - len2; i++) {
        char* substr = (char*)malloc(len2 + 1);
        strncpy(substr, s1 + i, len2);
        substr[len2] = '\0';

        if (strcmp(substr, s2) == 0) {
            count++;
        }

        free(substr);
    }

    return count;
}
