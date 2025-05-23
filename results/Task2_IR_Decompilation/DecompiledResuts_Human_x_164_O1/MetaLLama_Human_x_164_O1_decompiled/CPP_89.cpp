#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char c = str[i];
        int shifted = (c - 93) % 26;
        char encrypted = shifted + 97;
        str[i] = encrypted;
    }
}

int main() {
    char str[256];
    scanf("%s", str);
    encrypt(str);
    printf("%s\n", str);
    return 0;
}
