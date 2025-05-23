#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_upper(char *s) {
    int count = 0;
    char *str = "AEIOU";
    char *ptr = s;

    while (*ptr != '\0') {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            int i;
            for (i = 0; i < 5; i++) {
                if (*ptr == str[i]) {
                    count++;
                    break;
                }
            }
        }
        ptr++;
    }

    return count;
}

int main() {
    char *s = "Hello World";
    printf("%d\n", count_upper(s));
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}
