#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_distinct_characters(char *str) {
    int len = strlen(str);
    char *s = str;

    if (len == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }

    int distinct = 0;
    char *t = NULL;
    char *u = NULL;
    char *v = NULL;

    for (int i = 0; i < len; i++) {
        int found = 0;
        for (int j = 0; j < distinct; j++) {
            if (v[j] == s[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (distinct == 0) {
                t = (char *)malloc(2);
            } else {
                char *tmp = (char *)malloc(distinct + 2);
                if (tmp == NULL) {
                    free(t);
                    return -1;
                }
                memcpy(tmp, t, distinct);
                free(t);
                t = tmp;
            }

            t[distinct] = s[i];
            distinct++;
            v = t;
        }
    }

    free(t);
    return distinct;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_distinct_characters("") == 0);
    assert (count_distinct_characters("abcde") == 5);
    assert (count_distinct_characters("abcdecadeCADE") == 5);
    assert (count_distinct_characters("aaaaAAAAaaaa") == 1);
    assert (count_distinct_characters("Jerry jERRY JeRRRY") == 5);
}
