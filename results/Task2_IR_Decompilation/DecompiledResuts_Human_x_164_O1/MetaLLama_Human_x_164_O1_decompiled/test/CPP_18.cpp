#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    unsigned long long _M_string_length;
    unsigned long long _M_allocated_capacity;
} string;

int how_many_times(string* str1, string* str2) {
    int result = 0;
    unsigned long long str1_len = str1->_M_string_length;
    unsigned long long str2_len = str2->_M_string_length;

    if (str1_len == 0) {
        return result;
    }

    unsigned long long i = 0;
    do {
        unsigned long long pos = i;
        if (pos >= str1_len) {
            break;
        }

        unsigned long long len = str1_len - pos;
        len = (len > str2_len) ? str2_len : len;

        if (len > 15) {
            char* substr = (char*)malloc(len + 1);
            memcpy(substr, str1->_M_dataplus._M_p + pos, len);
            substr[len] = 0;
            if (strcmp(substr, str2->_M_dataplus._M_p) == 0) {
                result++;
            }
            free(substr);
        } else {
            if (memcmp(str1->_M_dataplus._M_p + pos, str2->_M_dataplus._M_p, len) == 0) {
                result++;
            }
        }

        i++;
    } while (i <= str1_len - str2_len);

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (how_many_times("", "x") == 0);
    assert (how_many_times("xyxyxyx", "x") == 4);
     assert (how_many_times("cacacacac", "cac") == 4);
    assert (how_many_times("john doe", "john") == 1);
}
