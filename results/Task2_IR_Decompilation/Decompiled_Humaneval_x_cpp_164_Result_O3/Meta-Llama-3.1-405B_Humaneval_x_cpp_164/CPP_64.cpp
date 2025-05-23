#include <string.h>

int vowels_count(const char* str) {
    const char* vowels = "aeiouAEIOU";
    int count = 0;
    int len = strlen(str);
    if (len > 0) {
        for (int i = 0; i < len; i++) {
            char c = str[i];
            switch (c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    count++;
                    break;
                default:
                    break;
            }
        }
        if (str[len - 1] == 'y' || str[len - 1] == 'Y') {
            count++;
        }
    }
    return count;
}
