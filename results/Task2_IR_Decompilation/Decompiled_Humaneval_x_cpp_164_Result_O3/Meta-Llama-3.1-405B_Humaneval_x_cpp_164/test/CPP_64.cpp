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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (vowels_count("abcde") == 2);
    assert (vowels_count("Alone") == 3);
    assert (vowels_count("key") == 2);
    assert (vowels_count("bye") == 1);
    assert (vowels_count("keY") == 2);
    assert (vowels_count("bYe") == 1);
    assert (vowels_count("ACEDY") == 3);
   
}
