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
