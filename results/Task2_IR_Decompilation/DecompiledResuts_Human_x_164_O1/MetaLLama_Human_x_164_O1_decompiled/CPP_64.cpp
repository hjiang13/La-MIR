#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vowels_count(const char* str) {
    int count = 0;
    const char* vowels = "aeiouAEIOU";
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        char c = str[i];
        if (c == 'y' || c == 'Y') {
            count++;
        } else {
            for (size_t j = 0; j < 10; j++) {
                if (vowels[j] == c) {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

int main() {
    const char* str = "Hello World";
    int count = vowels_count(str);
    printf("%d\n", count);
    return 0;
}
