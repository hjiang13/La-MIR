#include <stdio.h>
#include <string.h>
#include <stdint.h>

int count_upper(const char* str) {
    const char* vowels = "AEIOU";
    int count = 0;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        char c = str[i];
        if (c == vowels[0] || c == vowels[1] || c == vowels[2] || c == vowels[3] || c == vowels[4]) {
            count++;
        }
    }
    return count;
}
