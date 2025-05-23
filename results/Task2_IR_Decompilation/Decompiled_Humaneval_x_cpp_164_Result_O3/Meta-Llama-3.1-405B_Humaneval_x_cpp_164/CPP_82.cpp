#include <stdio.h>
#include <string.h>

typedef struct {
    char* _M_p;
    long long _M_string_length;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    long long _M_string_length;
    long long _M_capacity;
} std_string;

int prime_length(std_string* s) {
    long long length = s->_M_string_length;
    int len = (int)length;
    if (len < 2) return 0;
    if (len < 4) return 1;
    int i = 2;
    while (1) {
        if (len % i == 0) {
            if (i * i > len) return 1;
            else return 0;
        }
        i++;
    }
    return 0;
}
