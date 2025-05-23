#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vowels_count(const char* str) {
    int count = 0;
    int len = strlen(str);
    const char* vowels = "aeiouAEIOU";
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}
