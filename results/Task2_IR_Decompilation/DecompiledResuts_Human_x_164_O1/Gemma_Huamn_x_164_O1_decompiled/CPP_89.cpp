```c
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    struct {
        char* _M_dataplus;
        size_t _M_len;
    } _Alloc_hider;
    size_t _M_capacity;
} string;

string* encrypt(string* s) {
    char* p = s->_M_dataplus;
    size_t len = s->_M_len;
    for (size_t i = 0; i < len; ++i) {
        char c = p[i];
        if (c >= 93) {
            c = c - 26;
        }
        p[i] = c + 97;
    }
    return s;
}
```