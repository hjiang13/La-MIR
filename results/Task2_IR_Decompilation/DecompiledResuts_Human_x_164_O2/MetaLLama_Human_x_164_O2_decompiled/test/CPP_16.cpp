#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int count_distinct_characters(const char* str) {
    char* s = (char*)str;
    int len = strlen(s);
    if (len == 0) return 0;

    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }

    char* t = (char*)malloc(len);
    char* t_end = t + len;
    char* p = s;
    char* q = t;
    char* r = t;

    while (p != s + len) {
        if (q == t_end) {
            size_t new_len = len * 2;
            if (new_len < len) {
                __throw_length_error("vector::_M_realloc_insert");
            }
            char* new_t = (char*)malloc(new_len);
            memmove(new_t, t, len);
            free(t);
            t = new_t;
            t_end = t + new_len;
            q = t + len;
            r = t + len;
        }
        if (*p == *q) {
            p++;
            q++;
            if (q == t_end) {
                len++;
                r++;
            }
        } else {
            *r = *p;
            r++;
            p++;
            q = r;
        }
    }

    int count = r - t;
    free(t);
    return count;
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
